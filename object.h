// Language::CwC

#pragma once

/*
 * Generic object class.
 */
class Object {
public:
  
  // default constructor
  Object() = default;
  
  // default destructor
  virtual ~Object() = default;
  
  // pure virtual hash function, to be implemented by child classes.
  virtual size_t hash() = 0;

  // check equality of two objects
  virtual bool equals(Object* other) = 0;

  // string representation of this object
  virtual const char* to_string() = 0;
};
