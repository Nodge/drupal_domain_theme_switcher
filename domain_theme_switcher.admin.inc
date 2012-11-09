<?php
// $Id:
/**
 * @file
 */


 /**
 * 
 */ 
function domain_theme_switcher_themes_configuration_form() {
	$themes = domain_theme_switcher_list_theme_names();
	$prefix = '';
	$warning = '';
	
	if (count($themes) == 0) {
		$warning = '<div class="message error">You must enable themes in order to use theme switching</div>';
	}  	
	
	$form['base'] = array(
		'#type' => 'fieldset',
		'#title' => t('Base theme options'),
		'#collapsible' => true,  
		'#collapsed' => false,
	);

	$form['base']['base_domain'] = array(
		'#type' => 'textfield',
		'#title' => t('Base domain name'),
		'#description' => t('Type the domain name (usually a subdomain with www.*) for the base theme. You can type multiple domain names separated by commas.'),
		'#default_value' => variable_get("base_domain", false),
	);
	
	
	$form['poor_vision'] = array(
		'#type' => 'fieldset',
		'#title' => t('Poor vision theme options'),
		'#collapsible' => true,  
		'#collapsed' => false,
	);

	$form['poor_vision']['poor_vision_domain'] = array(
		'#type' => 'textfield',
		'#title' => t('Poor vision domain name'),
		'#description' => t('Type the domain name (usually a subdomain with poor.*) for the poor vision theme.'),
		'#default_value' => variable_get("poor_vision_domain", false),
	);
  	
	if (count($themes) > 0 ) {
		$form['poor_vision']['poor_vision_theme_name'] = array(
			'#type' => 'select',
			'#title' => t('Poor vision theme'),
			'#default_value' => variable_get("poor_vision_theme_name", false),
			'#options' => $themes,
			'#description' => t('Select your default poor vision theme.'),
		);
	}
	
	
	$form['mobile'] = array(
		'#type' => 'fieldset',
		'#title' => t('Mobile theme options'),
		'#collapsible' => true,  
		'#collapsed' => false,
	);

	$form['mobile']['mobile_domain'] = array(
		'#type' => 'textfield',
		'#title' => t('Mobile domain name'),
		'#description' => t('Type the domain name (usually a subdomain with mobile.*) for the mobile theme.'),
		'#default_value' => variable_get("mobile_domain", false),
	);

	if (count($themes) > 0 ) {
		$form['mobile']['mobile_theme_name'] = array(
			'#type' => 'select',
			'#title' => t('Poor vision theme'),
			'#default_value' => variable_get("mobile_theme_name", false),
			'#options' => $themes,
			'#description' => t('Select your default poor vision theme.'),
		);
	}
	

	return system_settings_form($form);
}

/**
 * Function returning the available themes
 */ 
function domain_theme_switcher_list_theme_names() {
	global $conf;
	$themes = list_themes();
	$list = array();
	foreach ($themes as $key => $value ) {
		if ($value->status == 1 ) {
			$list[] = $key;
		}    
	}
	
	if (count($list) == 0) {
		return array();
	} 
	else {
		return array_combine($list, $list);
	}
}

