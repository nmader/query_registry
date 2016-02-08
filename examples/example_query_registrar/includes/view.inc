<?php

/**
 * @file
 * Example page.
 */

/**
 * Example page callback.
 */
function example_query_registrar_view() {
  $renderable = array();

  // Showcasing soft dependency to ease user adoption.
  $results = NULL;
  if (module_exists('query_registry')) {
    $results = query_registry_run_query('example_query', array('Or is it?'));
  }

  // Module's default query.
  if (is_null($results)) {
    $results = array('There', 'will', 'be', 'cake.');
  }

  $renderable = implode(' ', $results);
  return $renderable;
}
