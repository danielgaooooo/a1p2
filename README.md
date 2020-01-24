# CwC API

This CwC API provides an interface to an Object and Map class implemented in CwC.  
  
## Usage
**Map**  
```
  void insert(String* key, Object* value);
 
  String** getKeys();

  Object* at(String* key);

  size_t size();

  void erase(String* key);

  void clear();

  size_t hash();

  bool equals(Object* other);

  const char* to_string();
```  
**Object**  
```
  size_t hash() = 0;

  bool equals(Object* other) = 0;

  const char* to_string() = 0;
```
