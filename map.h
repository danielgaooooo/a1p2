/*
 * Authors: Brian Yeung, Daniel Gao
 * CS4500 Assignment 1, Part 2
 */

// Lang::CwC
#pragma once

#include "object.h"
#include "string.h"

/**
 * CwC implementation of a HashMap.
 */
class Map : public Object {
public:
  Map() = default;

  virtual ~Map() = default;

  // Inserts key and value as references
  void insert(String* key, Object* value) {
  }
 
  // Returns all keys as a fixed-length array
  Object** getKeys() {
    return nullptr;
  }

  // Returns the value at this key
  Object* at(String* key) {
    return nullptr;
  }

  // Returns the number of key-value pairs in this map
  size_t size() {
    return 0;
  }

  // Removes the key-value pair associated with this key
  void erase(String* key) {
  }

  // Clears the entire map, frees elements from memory
  void clear() {
  }

  virtual size_t hash() {
    return 0;
  }

  virtual bool equals(Object* other) {
    return false;
  }

  // No supported implementation for map!
  virtual const char* to_string() {
    return nullptr;
  }
};
