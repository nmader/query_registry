<?php

/**
 * @file
 * Example query implementation functions.
 */

/**
 * This is an example query implementation.
 *
 * @param string $arg
 *   Arguments passed would usually be something being searched for.
 */
function example_implementation_registrar_query_implementation($arg) {
  return array('The', 'cake', 'is', 'a', 'lie!', $arg);
}
