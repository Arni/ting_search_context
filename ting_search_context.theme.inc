<?php

/**
 * @file
 * Theme functions used with the ting search context.
 */

/**
 * Implements default preprocess function for the search context.
 */
function template_preprocess_ting_search_context(&$vars, $hook) {
  // Add Javascript settings
  drupal_add_js(array('ting_search_context' => $vars[context]), 'setting');
  drupal_add_js(array('ting_search_context_position' => $vars[position]), 'setting');

  // Add JavaScript and CSS using wrapper functions.
  _ting_search_context_add_javascript();
  _ting_search_context_add_css();
}

/**
 * Implements default preprocess function for the search context content.
 */
function template_preprocess_ting_search_context_content(&$vars, $hook) {
  $node = $vars[node];

  //Image
  $field_name = ting_search_context_get_image_field_name($node);
  $image = field_view_field('node', $node, $field_name, array(
    'label' => 'hidden',
    'settings' => array(
      'image_style' => 'ting_search_context',
    ),
  ));
  $vars[image] = drupal_render($image);

  //URL
  $url = url(drupal_get_path_alias('node/' . $node->nid), array('absolute' => TRUE));
  $url .= '?WT.cg_n=searchcontext';
  $vars[url] = $url;

  // Title
  $vars[title] = check_plain($node->title);

}


