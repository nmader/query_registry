<?php

/**
 * @file
 * Hook and callback implementations.
 */

/**
 * Defines a set of queries that can be overridden.
 *
 * @return array
 *   An associative array of associative arrays which define queries. Each
 *   query should consist of a unique name mapped to an array of properties:
 *   - name: A human readable name for the query.
 *   - description: A description of the query.
 */
function hook_query_registry_register_queries() {
  return array(
    'my_query' => array(
      'name' => t('My Query'),
      'description' => t('It is awesome!'),
    ),
  );
}

/**
 * Defines a set of query implementations.
 *
 * @return array
 *   An associative array of associative arrays which define query
 *   implementations. Query implementations are expected to return a non-NULL
 *   value. Each query implementation's key should be that of a query and each
 *   definition should consist a mapping to an array of properties:
 *   - name: A human readable name for the implementation.
 *   - description: A description of the implementation.
 *   - module: The module containing the implementation.
 *   - extension: The extension of the file containing the implementation.
 *   - filename: The name of the file containing the implementation.
 *   - callable: A PHP callable for the implementation.
 *   - configure_path: Path to configure the implementation at.
 */
function hook_query_registry_register_implementations() {
  return array(
    'my_query' => array(
      'name' => t('My Query Implementation'),
      'description' => t('It is super awesome!'),
      'module' => 'foo',
      'filename' => 'bar',
      'extension' => 'bom',
      'callable' => 'foo_baz',
      'configure_path' => 'admin/foo',
    ),
  );
}
