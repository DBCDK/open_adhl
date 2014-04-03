<?php

/**
 * @file
 * OpenHoldingsStatus : open_holdingstatus class
 **/

class OpenAdhlRequest extends TingClientRequest Implements ITingClientRequestCache {

  protected $numRecords;
  protected $id;
  protected $cacheKey;
  protected $outputType;
  protected $action;
  protected $callback;


  /* Implementation of ITingClientRequestCache */

  /** \brief ITingClientRequestCache::cacheKey; get a cachekey
   *
   * @return string
   **/
  public function cacheKey() {
    $params = $this->getParameters();
    $ret = '';
    $this->make_cache_key($params, $ret);

    return md5($ret);
  }

  /** \brief make a cachekey based on request parameters
   *
   * @param array $params
   * @param string $ret
   **/
  private function make_cache_key($params, &$ret) {
    foreach ($params as $key => $value) {
      if (is_array($value)) {
        // recursive
        $ret .= $key;
        $this->make_cache_key($value, $ret);
      }
      else {
        $ret .= $value;
      }
    }
  }

  /** \brief ITingClientRequestCache::cacheEnable; Check if cache is enabled
   *
   * @return value of variable (drupal_get)
   **/
  public function cacheEnable($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_enable);
  }

  /** \brief set timeout of cache
   *
   * @return mixed value of variable (variable_get)
   **/
  public function cacheTimeout($value = NULL) {
    $class_name = get_class($this);
    return variable_get($class_name . TingClientRequest::cache_lifetime, '1');
  }

  /** \brief implements ITingClientRequestCache::cacheBin
   *
   * @return string; name of cachebin
   **/
  public function cacheBin() {
    return 'cache_adhl_webservice';
  }


  public function setId($value = NULL) {
    $this->id = $value;
  }

  public function getId() {
    return $this->id;
  }

  public function setNumRecords($value = NULL) {
    $this->numRecords = $value;
  }

  public function getNumRecords() {
    return $this->numRecords;
  }

  public function setAction($value = NULL) {
    $this->action = $value;
  }

  public function getAction() {
    return $this->action;
  }

  public function getCallback() {
    return $this->callback;
  }

  public function setCallback($callback) {
    $this->callback = $callback;
  }

  public function setOutputType($value = NULL) {
    $this->outputType = $value;
  }

  public function getOutputType() {
    return $this->outputType;
  }

  // empty;
  public function processResponse(stdClass $result) {
    return $result;
  }

}
