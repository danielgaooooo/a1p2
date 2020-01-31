# CwC API

This CwC API provides an interface to an Object and Map class implemented in CwC.  
  
## Usage
**Map**  
```
  // Inserts the key-value pair into the map
  void insert(String* key, Object* value);
 
  // Returns all keys of the map as an array of String*
  String** getKeys();

  // Returns the value associated with a certain key
  Object* at(String* key);

  // Returns the number of key-value pairs in this map
  size_t size();

  // Removes the key-value pair associated with this key
  void erase(String* key);

  // Removes all key-value pairs in the map (so size() == 0 afterwards)
  void clear();

  // Computes a value used by equals() that is based on value-equality. If
  // two maps have the same elements, they will have the same hash.
  size_t hash();

  // Computes if this map is equal to that object based on value
  bool equals(Object* other);
  
  // Returns a string version of this map
  const char* to_string();
```  
**Object**  
```
  // Computes a number based on the object's value to help determine equality
  size_t hash() = 0;

  // Checks if 2 objects are the same based on value
  bool equals(Object* other) = 0;

  // Returns a string version of this object
  const char* to_string() = 0;
```
