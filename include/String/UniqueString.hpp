#pragma once

#include <set>
#include <string>

namespace THelper
{
namespace String
{

template <class String, unsigned Category = 0> class UniqueString
{
public:
  UniqueString() : UniqueString(default_name)
  {}

  UniqueString(String s) : content(storeUniqueString(s))
  {
  }

  operator String () const
  {
    return getContent();
  }

  String getContent() const
  {
    return *content;
  }

  bool empty() const
  {
    return content->empty();
  }

  static void setDefaultName(const String& name)
  {
    default_name = name;
  }

  ~UniqueString()
  {
    names_in_use.erase(content);
  }

  UniqueString(const UniqueString &) = delete;
  UniqueString& operator=(const UniqueString &) = delete;
  UniqueString(const UniqueString &&) = delete;
  UniqueString& operator=(const UniqueString &&) = delete;

private:
  typedef std::set<String> Container;
  typedef typename Container::iterator ContainerIterator;

  ContainerIterator storeUniqueString(String proposition)
  {
    String to_add = findUniqueName(proposition);
    auto ret = names_in_use.insert(to_add);
    return ret.first;
  }


  String findUniqueName(String proposition)
  {
    if (names_in_use.find(proposition) == names_in_use.end())
    {
      return proposition;
    }
    unsigned i = 2;
    String proposition_accumulator = proposition + std::to_string(i++);
    while (names_in_use.find(proposition_accumulator) != names_in_use.end())
    {
      proposition_accumulator = proposition + std::to_string(i++);
    }
    return proposition_accumulator;
  }

  ContainerIterator content;
  static Container names_in_use;
  static String default_name;
};

using UniqueStdString = UniqueString<std::string, 0>;
template <unsigned Category> using UniqueStdCategorizedString = UniqueString<std::string, Category>;

template <class String, unsigned Category> typename UniqueString<String, Category>::Container UniqueString<String, Category>::names_in_use;
template <class String, unsigned Category> String UniqueString<String, Category>::default_name{"UniqueStringDefault"};

template <class String, unsigned Category> bool operator==(const String &s, const UniqueString<String, Category> &us)
{
  return s == static_cast<String>(us);
}

template <class String, unsigned Category> bool operator==(const UniqueString<String, Category> &us, const String &s)
{
  return s == us;
}

template <class String, unsigned Category> bool operator!=(const String &s, const UniqueString<String, Category> &us)
{
  return !(s == us);
}

template <class String, unsigned Category> bool operator!=(const UniqueString<String, Category> &us, const String &s)
{
  return s != us;
}

template <class String, unsigned Category> bool operator==(const UniqueString<String, Category> &us1, const UniqueString<String, Category> &us2)
{
  return static_cast<String>(us1) == us2;
}

template <class String, unsigned Category> bool operator!=(const UniqueString<String, Category> &us1, const UniqueString<String, Category> &us2)
{
  return static_cast<String>(us1) != us2;
}

}
}