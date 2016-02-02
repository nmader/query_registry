<?php

/**
 * @file
 * Main configuration form functions for the module.
 */

/**
 * Main configuration form for the module.
 */
function query_registry_admin_form() {
  $form = array('#tree' => TRUE);
  $radios = array();
  $defaults = variable_get('query_registry_selected_queries', array());

  $queries = module_invoke_all(QUERY_REGISTRY_REGISTER_QUERY);
  foreach ($queries as $query => $query_def) {
    $description = isset($query_def['description']) ? $query_def['description'] : '';
    $radios[$query] = array(
      '#type' => 'radios',
      '#title' => check_plain($query_def['name']),
      '#description' => check_plain($description),
      '#default_value' => isset($defaults[$query]) ? $defaults[$query] : NULL,
      '#options' => array('module_default' => t('No override')),
    );

    $implementations = array();
    $implementation_modules = module_implements(QUERY_REGISTRY_REGISTER_IMPLEMENTATION);
    foreach ($implementation_modules as $module) {
      $implementations[$module] = module_invoke($module, QUERY_REGISTRY_REGISTER_IMPLEMENTATION);
    }

    foreach ($implementations as $name => $implementation) {
      if (isset($implementation[$query])) {
        $configure = isset($implementation[$query]['configure_path']) ? l(t('Configure'), $implementation[$query]['configure_path']) : '';
        $description = isset($implementation[$query]['description']) ? "</br>{$implementation[$query]['description']}" : '';
        $radios[$query]['#options'][$name] = "{$implementation[$query]['name']} $configure $description";
      }
    }
  }
  $form['head']['#markup'] = t('This query registry lets you control how queries will be performed on your site.');
  $form['query_registry_selected_queries'] = $radios;

  return system_settings_form($form);
}
