//Author: Aniruddh Kathiriya
//Assignment:4
#include "set.h"
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

set::set(size_type initial_capacity){
	used=0;
	data=new value_type[initial_capacity];
	capacity=initial_capacity;
}

set::~set(){
	delete[] data;
}

set::set (const set& source){
	used=source.used;
	capacity=source.capacity;
	data=new value_type[capacity];
	copy(source.data,source.data+used,data);
}

set& set::operator = (const set& source){
	if(this==&source){
		return *this;
	}
	if(capacity!=source.capacity){
	delete[] data;
	data=new value_type[source.capacity];
	capacity=source.capacity;
	}
	copy(source.data,source.data+used,data);
	used=source.used;
	return *this;
}

void set::insert(const value_type& entry){
	if(!(contains(entry))){
		if(size()==capacity){
			resize(capacity*2);
		}
		data[used]=entry;
		used++;	
	}
}

void set::remove(const value_type& entry){
	for (size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			data[i]=data[used-1];
			used--;
		}
		
	}
}

set::size_type set::size() const{
	return used;
}

bool set::contains (const value_type& entry) const{
	for (size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			return true;
		}
		
	}
	return false;
}

std::ostream& operator << (std::ostream& output, const set& s){
	for(set::size_type i=0;i<s.size();i++){
	output<<s.data[i]<<" ";
	}
	return output;
}

set set_union (const set& s1, const set& s2){
	set s3;
	for(set::size_type i=0;i<s1.size();i++){
		s3.insert(s1.data[i]);
	}
	for(set::size_type i=0;i<s2.size();i++){
		s3.insert(s2.data[i]);
	}
	return s3;
}

set set_intersection(const set& s1, const set& s2){
	set s3;
	if(s1.size()>s2.size()){
		for(set::size_type i=0;i<s2.size();i++){
			if(s1.contains(s2.data[i])){
				s3.insert(s2.data[i]);
			}
		}
	}else{
		for(set::size_type i=0;i<s1.size();i++){
			if(s2.contains(s1.data[i])){
				s3.insert(s2.data[i]);
			}
		}
	}

	return s3;
	
}

set set_difference (const set& s1, const set& s2){
	set s3;
		for(set::size_type i=0;i<s2.size();i++){
			if(!(s1.contains(s2.data[i]))){
				s3.insert(s1.data[i]);
			}
		}
	
	return s3;
	
}

bool is_subset (const set& s1, const set& s2){
		for(set::size_type i=0;i<s1.size();i++){
			if(!(s2.contains(s1.data[i]))){
				return false;
			}
		}
		return true;
}

set::size_type set::find (const value_type& entry) const{
	for (set::size_type i=0;i<used;i++ ){
		if(data[i]==entry){
			return i;
		}
		
	}
	return used;
}

bool operator == (const set& s1, const set& s2){
	if(s1.size()!=s2.size()){
		return false;
	}
	return is_subset(s1,s2);
}

void set::resize (unsigned int new_size){
	if(capacity==new_size || capacity<used){
		return;
	}
	value_type* temp= new value_type[new_size];
	copy(data,data+used,temp);
	delete[] data;
	data=temp;
	capacity=new_size;
}
