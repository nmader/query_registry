<?php

/**
 * @file
 * Hook and callback implementations.
 */

/**
 * Override the existing example query.
 *
 * Callback for example_query_registrar_view().
 * This corresponds to the registered query `example_query`.
 *
 * @param string $arg
 *   Arguments passed would usually be something being searched for.
 *
 * @return array
 *   The results of the query.
 */
function callback_example_query_implementation($arg) {
  return array('It', 'is', 'not', 'something', 'you', 'will', 'believe.', $arg);
}
