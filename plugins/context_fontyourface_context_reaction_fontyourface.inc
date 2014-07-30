<?php
/**
 * Expose @fontyourface fonts as context reactions.
 */
class context_fontyourface_context_reaction_fontyourface extends context_reaction {
  /**
   * Allow admins to provide additional body classes.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array(
      'fontyourface' => array(
        '#title' => t('Do Not Load Fonts'),
        '#description' => t('By default, the @font-your-face modules loads fonts on every page. Check this box to suppress font loading.'),
        '#type' => 'checkbox',
        '#default_value' => isset($values['fontyourface']) ? $values['fontyourface'] : 0,
      ),
    );
    return $form;
  }
  
  /**
   * Public method that is called from hooks or other integration points.
   */
  function execute() {
    foreach ($this->get_contexts() as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['fontyourface'])) {
        return true;
      }
    }
  }
}