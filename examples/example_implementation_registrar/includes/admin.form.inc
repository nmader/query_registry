<?php

/**
 * @file
 * Main configuration form functions for the module.
 */

/**
 * Main configuration form for the module.
 */
function example_implementation_registrar_admin_form() {
  $form = array();

  $form['foo'] = array(
    '#markup' => t('This is an example query configuration.'),
  );

  return $form;
}
