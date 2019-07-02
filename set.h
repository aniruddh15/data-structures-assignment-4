#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
  typedef int value_type;
  typedef std::size_t size_type;
  static const size_type INITIAL_CAPACITY = 30;

  set(size_type initial_capacity = INITIAL_CAPACITY);
// postcondition: empty set has been created

  ~set();
// postcondition: set has been deallocated
  
  set (const set& source);
  // postcondition: a copy of source has been created

  set& operator = (const set& source);
  // postcondition: 
  //efficiency:O(n)
  
  void insert (const value_type& entry);
  // postcondition: entry is in the set
  //efficiency:O(n^2)

  void remove (const value_type& entry);
// postcondition: entry is not in the set
	//efficiency:O(n)

  size_type size() const;
// postcondition: number of elements in the set has been returned
	//efficiency:O(1)

  bool contains (const value_type& entry) const;
// postcondition: whether entry is in the set has been returned
	//efficiency:O(n)

  friend set set_union (const set& s1, const set& s2);
  //postcondition: union of s1 & s2 has been returned
  //efficiency:O(2n^3)

  friend set set_intersection (const set& s1, const set& s2);
  // postcondition: intersection of s1 & s2 has been returned
  //efficiency:O(n^4)

  friend set set_difference (const set& s1, const set& s2);
// postcondition: difference of s1 - s2 has been returned
	//efficiency:O(n^4)

  friend bool is_subset (const set& s1, const set& s2);
// postcondition: returned whether s1 is a subset of s2
	//efficiency:O(n^2)

  friend bool operator == (const set& s1, const set& s2);
  // postcondition: returned whether s1 & s2 are equal
  //efficiency:O(n^2)

  friend std::ostream& operator << (std::ostream& output, const set& s);
// postcondition: s has been displayed on output
	//efficiency:O(n)

private:
  size_type find (const value_type& entry) const;
  //efficiency:O(n)
  
  // returned location of entry in the set if entry is in the set - used otherwise
  void resize (unsigned int new_size);
  //efficiency:O(n)
  
  value_type* data;
  size_type used;
  size_type capacity;
};


#endif