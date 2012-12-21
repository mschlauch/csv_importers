<?php
/**
 * @file
 * csv_importers.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function csv_importers_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'article_importer';
  $feeds_importer->config = array(
    'name' => 'Article Importer',
    'description' => 'a multilingual Article Importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'article',
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Tags - T-Menu',
            'target' => 'field_tags',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title - italian',
            'target' => 'title_field:et:it',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Body - italian',
            'target' => 'body:et:it',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title - german',
            'target' => 'title_field:et:de',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Body - german',
            'target' => 'body:et:de',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Title - english',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Body - english',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Author',
            'target' => 'user_name',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Date',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['article_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'basic_page_importer';
  $feeds_importer->config = array(
    'name' => 'Basic Page Importer',
    'description' => 'a multilingual importer of basic page content',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'page',
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Tags - T-Menu',
            'target' => 'field_tags',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Title - italian',
            'target' => 'title_field:et:it',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Body - italian',
            'target' => 'body:et:it',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Title - german',
            'target' => 'title_field:et:de',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Body - german',
            'target' => 'body:et:de',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Title - english',
            'target' => 'title_field:et:en',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Body - english',
            'target' => 'body:et:en',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['basic_page_importer'] = $feeds_importer;

  return $export;
}
