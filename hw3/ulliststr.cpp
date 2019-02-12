#include <cstdlib>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)
{
	if(empty()){
		Item* item = new Item;
		item->val[0] = val;
		item->last++;
		head_ = item;
		tail_ = item;
	}
	else{
		if(tail_->last==ARRSIZE){
			Item* item = new Item;
			item->val[0] = val;
			item->last++;
			item->prev = tail_;
			tail_->next = item;
			tail_ = item;
		}
		else{
			tail_->val[tail_->last] = val;
			tail_->last++;
		}
	}
	size_++;
}

void ULListStr::push_front(const std::string& val)
{
	if(empty()){
		Item* item = new Item;
		item->val[ARRSIZE-1] = val;
		item->first = ARRSIZE-1;
		item->last = ARRSIZE;
		head_ = item;
		tail_ = item;
	}
	else{
		if(head_->first==0){
			Item* item = new Item;
			item->val[ARRSIZE-1] = val;
			item->first = ARRSIZE-1;
			item->last = ARRSIZE;
			item->next = head_;
			head_->prev = item;
			head_ = item;
		}
		else{
			head_->val[head_->first-1] = val;
			head_->first--;
		}
	}
	size_++;
}

void ULListStr::pop_back()
{
	if(empty()) return;
	tail_->val[tail_->last-1] = "";
	tail_->last--;
	size_--;
	if(tail_->first==tail_->last){
		if(size_==0){
			delete tail_;
			head_ = NULL;
			tail_ = NULL;
		}
		else{
			tail_ = tail_->prev;
			delete tail_->next;
			tail_->next = NULL;
		}
	}
}

void ULListStr::pop_front()
{
	if(empty()) return;
	head_->val[head_->first] = "";
	head_->first++;
	size_--;
	if(head_->first==head_->last){
		if(size_==0){
			delete head_;
			head_ = NULL;
			tail_ = NULL;
		}
		else{
			head_ = head_->next;
			delete head_->prev;
			head_->prev = NULL;
		}
	}
}

std::string const & ULListStr::back() const
{
	if(empty()) return NULL;
	return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
	if(empty()) return NULL;
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	if(loc<0 || loc>=size_) return NULL;
	size_t headL = head_->last - head_->first;
	size_t tailL = tail_->last - tail_->first;
	if(loc<headL){ // loc+1 <= headL: loc in head
		return head_->val+head_->first+loc;
	}
	if(size_-tailL >= loc+1) { // size_-headL-tailL >= loc+1-headL: loc in body
		Item* temp = head_->next;
		loc = loc - headL;
		while(loc>=ARRSIZE){
			temp = temp->next;
			loc = loc-ARRSIZE;
		}
		return temp->val+loc;
	}
	if(size_-(loc+1) < tailL){ // loc in tail
		return tail_->val+(loc-size_+tailL); // loc-(size_-headL-tailL)-headL
	}
	return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
// hw3
ULListStr::ULListStr (const ULListStr& other)
{
	head_ = NULL; // initialize values
  	tail_ = NULL;
  	size_ = 0;
	appendContents(other);
}

ULListStr& ULListStr::operator= (const ULListStr& other)
{
	if(this == &other) return *this; // self assignment
	clear(); // cleanup initialized members
	appendContents(other);
	return *this;
}

ULListStr ULListStr::operator+ (const ULListStr& other) const
{
	ULListStr result(*this);
	result.appendContents(other);
	return result;
}

ULListStr& ULListStr::operator-= (size_t num)
{
	if(empty()) return *this;
	for(size_t i=0;i<num;i++){
		if(empty()) break;
		if(tail_->last==0){
			tail_ = tail_->prev;
			delete tail_->next;
			tail_->next = NULL;
		}
		tail_->last--;
		size_--;
	}
	return *this;
}

std::string const & ULListStr::operator[] (size_t loc) const
{
	if(loc<0||loc>=size_) 
		throw std::out_of_range ("loc out of range");
	return get(loc);
}

std::string & ULListStr::operator[] (size_t loc)
{
	if(loc<0||loc>=size_) 
		throw std::out_of_range ("loc out of range");
	return get(loc);
}

void ULListStr::appendContents(const ULListStr& other)
{
	for(size_t i = 0;i < other.size();i++){
		push_back(other.get(i));
	}
}