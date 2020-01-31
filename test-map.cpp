#include <cctype>
#include <cstdio>
#include <cstdlib>
#include "object.h"
#include "string.h"
#include "map.h"

// ==================== TESTING TOOLS ====================
int test_counter = 0;
void FAIL() {
  printf("Test %d failed!\n", test_counter);
  exit(1);
}

void OK(const char* m) {
  printf("%s\n", m);
}

void t_true(bool p) {
  test_counter++;
  if (!p) 
    FAIL(); 
  printf("Test %d passed!", test_counter);
}

void t_false(bool p) { 
  test_counter++;
  if (p) 
    FAIL(); 
  printf("Test %d passed!", test_counter);
}

// ==================== CwC API TESTS ====================
void testHash() {
  String* empty = new String();
  String* key1 = new String("Key Bob");
  String* key1Copy = new String("Key Bob");
  String* key2 = new String("Key Joe");
  String* key3 = new String("Key Ann");
  
  t_true(empty->hash() == empty->hash());
  t_false(empty->hash() == key1->hash());
  t_true(key1->hash() == key1->hash());
  t_true(key1Copy->hash() == key1->hash());
  t_true(key1->hash() == key1Copy->hash());
  t_false(key1->hash() == key2->hash());
  t_false(key2->hash() == key3->hash());

  Map* emptyMap = new Map();
  Map* map1 = new Map();
  Map* map2 = new Map();
  Map* map3 = new Map();
  Object* val1 = new String("Value Bob");
  Object* val2 = new String("Value Ann");
  map1->insert(key1, val1);
  map2->insert(key1, val1);
  map3->insert(key1, val1);
  map3->insert(key2, val2);
  
  t_true(emptyMap->hash() == emptyMap->hash());
  t_false(emptyMap->hash() == map1->hash());
  t_true(map1->hash() == map1->hash());
  t_true(map1->hash() == map2->hash());
  t_false(map2->hash() == map3->hash());
  
  delete empty;
  delete key1;
  delete key1Copy;
  delete key2;
  delete key3;
  delete emptyMap;
  delete map1;
  delete map2;
  delete map3;
  delete val1;
  delete val2;
  OK("testHash Passed!");
}

void testEquals() {
  String* empty = new String();
  String* key1 = new String("Key Bob");
  String* key2 = new String("Key Joe");
  String* key3 = new String("Key Ann");
  t_true(empty->equals(empty));
  t_false(empty->equals(key1));
  t_true(key1->equals(key1));
  t_false(key1->equals(key3));
  t_false(key3->equals(key1));
  t_true(key1->equals(key1));

  Map* map1 = new Map();
  Map* map2 = new Map();
  Map* map3 = new Map();
  Object* val1 = new String("Value Bob");
  Object* val2 = new String("Value Ann");
  map2->insert(key1, val1);
  map3->insert(key1, val1);
  
  t_true(map1->equals(map1));
  t_true(map2->equals(map3));
  t_true(map3->equals(map2));
  t_true(map2->equals(map2));

  t_false(map1->equals(map2));
  t_false(map1->equals(map3));

  map3->insert(key2, val2);
  t_false(map2->equals(map3));
  t_false(map1->equals(map3));

  delete empty;
  delete key1;
  delete key2;
  delete key3;
  delete map1;
  delete map2;
  delete map3;
  delete val1;
  delete val2;
  OK("testEquals Passed!");
}

void testToString() {
  String* empty = new String();
  String* key1 = new String("Key Bob");
  String* key2 = new String("Key Ann");
  Object* emptyObj = new String();
  Object* obj1 = new String("Obj Bob");
  Object* obj2 = new String("Obj Ann");
  
  t_true(strcmp(empty->to_string(), "") == 0);
  t_true(strcmp(key1->to_string(), "Key Bob") == 0);
  t_true(strcmp(key2->to_string(), "Key Ann") == 0);
  t_true(strcmp(emptyObj->to_string(), "") == 0);
  t_true(strcmp(obj1->to_string(), "Obj Bob") == 0);
  t_true(strcmp(obj2->to_string(), "Obj Ann") == 0);
  
  delete empty;
  delete key1;
  delete key2;
  delete emptyObj;
  delete obj1;
  delete obj2;
  OK("testToString Passed!");
}

void testMap() {
  String* key1 = new String("Key Bob");
  String* key2 = new String("Key Ann");
  String* key3 = new String("Key Joe");

  Map* emptyMap = new Map();
  Map* map2 = new Map();
  Map* map3 = new Map();
  Map* mapInMap = new Map();
  Object* val1 = new String("Value Bob");
  Object* val2 = new String("Value Ann");
  Object* val3 = new String("Value Joe");
  map2->insert(key1, val1);
  map3->insert(key1, val1);
  map3->insert(key2, val2);
  map3->insert(key3, val3);
  mapInMap->insert(key1, val3);
  mapInMap->insert(key2, map3);
  
  t_true(emptyMap->at(key1) == nullptr);
  t_true(map2->at(key1)->equals(val1));
  t_true(map3->at(key1)->equals(val1));
  t_true(map3->at(key2)->equals(val2));
  t_true(map3->at(key3)->equals(val3));
  t_true(mapInMap->at(key1)->equals(val3));
  t_true(mapInMap->at(key2)->equals(map3));
  
  t_true(emptyMap->size() == 0);
  t_true(map2->size() == 1);
  t_true(map3->size() == 3);
  t_true(mapInMap->size() == 2);
  
  Object** map2Keys = new Object*[map2->size()];
  map2Keys[0] = key1;
  Object** map3Keys = new Object*[map3->size()];
  map3Keys[0] = key1;
  map3Keys[1] = key2;
  map3Keys[2] = key3;
  Object** mapInMapKeys = new Object*[mapInMap->size()];
  mapInMapKeys[0] = key1;
  mapInMapKeys[1] = key2;
  
  t_true(emptyMap->getKeys() == nullptr);
  t_true(map2->getKeys()[0]->equals(map2Keys[0]));
  t_true(map3->getKeys()[0]->equals(map3Keys[0]));
  t_true(map3->getKeys()[1]->equals(map3Keys[1]));
  t_true(map3->getKeys()[2]->equals(map3Keys[2]));
  t_true(mapInMap->getKeys()[0]->equals(mapInMapKeys[0]));
  t_true(mapInMap->getKeys()[1]->equals(mapInMapKeys[1]));

  //erase
  map2->erase(key1);
  map3->erase(key1);
  t_true(map2->at(key1) == nullptr);
  t_true(map2->size() == 0);
  t_true(map3->at(key1) == nullptr);
  t_true(map3->size() == 2);
  
  map3->erase(key3);
  t_true(map3->at(key3) == nullptr);
  t_true(map3->size() == 1);
  
  map3->insert(key3, val3);
  t_true(map3->at(key3) == val3);
  t_true(map3->size() == 2);
  
  mapInMap->erase(key2);
  t_true(mapInMap->at(key2) == nullptr);
  t_true(mapInMap->size() == 1);
  
  mapInMap->insert(key2, map3);
  t_true(mapInMap->at(key2) == map3);
  t_true(mapInMap->size() == 2);
  
  emptyMap->clear();
  map2->clear();
  map3->clear();
  mapInMap->clear();
  t_true(emptyMap->size() == 0);
  t_true(map2->size() == 0);
  t_true(map3->size() == 0);
  t_true(mapInMap->size() == 0);
  delete key1;
  delete key2;
  delete key3;
  delete emptyMap;
  delete map2;
  delete map3;
  delete mapInMap;
  delete val1;
  delete val2;
  delete val3;
  delete[] map2Keys;
  delete[] map3Keys;
  delete[] mapInMapKeys;
  OK("testMap Passed!");
}

int main() {
  testHash();
  testEquals();
  testToString();
  testMap();
  return 0;
}
