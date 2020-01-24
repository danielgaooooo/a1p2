// Language::CwC

#pragma once

#include <cstring>
#include "object.h"

/*
 * Represents a string value. Is of type Object.
 */
class String : public Object {
public:
  
  // =============================== METHODS ===============================
  
  // Default constructor.
  String() = default;
  
  // Constructor that accepts a string as a value.
  String(const char* value) : _val(value) {
  }
  
  // Default destructor.
  virtual ~String() = default;
  
  // Concats the given string to the current string
  String* concat(String* other)
  {
    const char* otherVal = other->to_string();
    char* currValMutable = strdup(_val);
    String* ret = new String(strcat(currValMutable, otherVal));
    return ret;
  }
  
  // computes hash value of string by alternatively summing and subtracting
  // ASCII values of characters in strings.
  virtual size_t hash() {
    size_t hash = 0;
    bool add = false;
    for (int i = 0; i < strlen(_val); ++i) {
      if (i % 4 == 0 && add) {
        hash += _val[i];
        add = false;
      } else {
        hash -= _val[i];
        add = true;
      }
    }
    return hash;
  }
  
  // checks equality of the given string with this string
  virtual bool equals(Object* other) {
    return strcmp(((String*)other)->to_string(), _val) == 0;
  }
  
  // returns the string value of this object as const char*
  virtual const char* to_string() {
    return _val;
  }

  // ================================ FIELDS ================================
  // value of string held by this object
  const char* _val;
};
