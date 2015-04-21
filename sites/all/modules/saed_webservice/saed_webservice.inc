<?php

/*
 * callback functions file
 * 
 * Documentation for function used:
 * node_type_load --> https://api.drupal.org/api/drupal/modules!node!node.module/function/node_load/7
 * node_load_multiple ---> https://api.drupal.org/api/drupal/modules!node!node.module/function/node_load_multiple/7
 * 
 */

function _saed_webservice_index($type_name){
    if(!node_type_load($type_name)){
        return services_error('node type '.$type_name.' not found' , 404);
    }
    $nodes_array = node_load_multiple([] , ['type' => $type_name]);
    if(empty($nodes_array)){
        return services_error('no nodes found that belong to node type: '.$type_name , 404);
    }
    return $nodes_array;
}