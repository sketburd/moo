// ordered_map.h: A light map ordered by insertion. Compatible with C++ version 20 
//                and higher.
#pragma once
#include <iterator>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>


// moo::ordered_map is a map ordered by insertion, like a stack or queue.
//
// Functions:
// - void push_back(Key, Value) : Adds a key-value pair to the tail of the map.
//     
//
// - void pop_back()            : Erase the element at the tail of the map.
//
//
// - Value get(Key)             : Get the key's associated value.
//
//
// - Value* get(Key)             : Get the key's associated value.
//
//
// - size_t size()              : Number of elements in the map.
//
//
// - bool empty()               : Returns true if their are no elements in the map,
//                                otherwise false.
//
// - Iterator begin()           : Returns an iterator to the first element in the
//                                ordered_map.
//
// - Iterator end()             : Returns an iterator to the element following
//                                the last element of the ordered_map.
//
// Online Help:
//
//      [insert link here]
//


namespace moo
{

  template <typename Key, typename Value>
  class ordered_map
  {
  private: 
  
    std::map<Key, size_t>              keys;
    std::vector<std::pair<Key, Value>> values;
    
    
    
    
  public:

    void push_back(Key key, Value value)
    {
      if (keys.find(key) != keys.end())
      {
        throw std::runtime_error("Error : Unable to push_back existing key."); 
      }
      
      values.push_back(std::make_pair(key, value));
      keys.insert({key, values.size() - 1});
    }


    void pop_back()
    {
      keys.erase(std::get<0>(values[values.size() - 1]));
      values.pop_back();
    }


    Value& get(Key key)
    {
      if (keys.find(key) == keys.end())
      {
        throw std::runtime_error("Error : Key not found."); 
      }
      return std::get<1>(values[keys[key]]);
    }
    
    
    size_t size() const
    {
      return values.size();
    }
    
    
    bool empty() const
    {
      return values.empty();
    }
    
    
    typename std::vector<std::pair<Key, Value>>::iterator begin()
    {
      return values.begin();
    }


    typename std::vector<std::pair<Key, Value>>::iterator end()
    {
      return values.end();
    }
    
  };
  
}



/* Unit Tests:
moo::ordered_map<std::string, int> map;
if (map.empty()) 
{ 
  std::cout << "good\n"; 
}
else
{ 
  std::cout << "error\n"; 
}
std::cout << "0:" << map.size() << "\n";
map.push_back("Terry", 52);
map.push_back("Gary", 10);
map.push_back("Jim", 34);
std::cout << "3:" << map.size() << "\n";
int value1 = map.get("Terry");
int value2 = map.get("Gary");
int value3 = map.get("Jim");
std::cout << "52:" << value1 << "\n";
std::cout << "10:" << value2 << "\n";
std::cout << "34:" << value3 << "\n";
map.get("Terry") = 53;
map.get("Gary") = 11;
map.get("Jim") = 35; 
std::cout << "53:" << map.get("Terry") << "\n";
std::cout << "11:" << map.get("Gary") << "\n";
std::cout << "35:" << map.get("Jim") << "\n";
std::cout << "Terry:53\nGary:11\nJim:35\n";
for (const std::pair<std::string, int>& element : map)
{
  std::cout << std::get<0>(element) << ":" << std::get<1>(element) << "\n";
}
map.pop_back();
map.pop_back();
std::cout << "Terry:53\n";
for (const std::pair<std::string, int>& element : map)
{
  std::cout << std::get<0>(element) << ":" << std::get<1>(element) << "\n";
}
map.pop_back();
if(map.empty())
{
  std::cout << "good\n";
}
else
{
  std::cout << "error\n";
}
std::cout << "Checking exception cases:\n";
try
{
  map.push_back("Terry", 42);
  map.push_back("Terry", 101);
}
catch (std::exception& e)
{
  std::cout << "E1:\n" <<  e.what() << "\n";
}
try
{
  map.get("Barry");
}
catch (std::exception& e)
{
  std::cout << "E2:\n" <<  e.what() << "\n";
}
std::cout << "fin" << std::endl;

// Expected Output:
// good
// 0:0
// 3:3
// 52:52
// 10:10
// 34:34
// 53:53
// 11:11
// 35:35
// Terry:53
// Gary:11
// Jim:35
// Terry:53
// Gary:11
// Terry:53
// good
// Checking exception cases:
// E1:
// Error : Unable to push_back existing key.
// E2:
// Error : Key not found.
// fin

*/

