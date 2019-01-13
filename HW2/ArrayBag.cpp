#include "ArrayBag.h"//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"


ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

bool ArrayBag::printOut(const ArrayBag &Bag){
    for(int i = 0 ; i < Bag.itemCount; i++){
        std::cout << Bag.items[i]<<" ";
    }
    return 1;
}
ArrayBag ArrayBag::operator-(const ArrayBag& A) {
    ArrayBag B;
    // Delete elements of B in A
    for(int i = 0 ; i < A.getCurrentSize(); i++) {
        while(contains(A.items[i])) {
            remove(A.items[i]);
        }
    }
    // Add element of A in C
    for(int i = 0 ; i < getCurrentSize(); i++){
        B.add(items[i]);
    }
    // Dedupe
    dedupe(B);
    return B;
}
ArrayBag ArrayBag::operator+(const ArrayBag& A)
{
    ArrayBag B;
    // Add A in C
    for(int i = 0 ; i < itemCount; i++){
        B.add(items[i]);
    }
    // Add B in C
    for(int i = 0 ; i < A.itemCount; i++){
        B.add(A.items[i]);
    }
    // Dedupe
    dedupe(B);

    return B;
}
void ArrayBag::dedupe(ArrayBag& A)
{
    for(int i = 0; i < A.getCurrentSize(); ) {
        int repeat = A.getFrequencyOf(A.items[i]);
        if (repeat == 1)
            i++;
        else {
            int n = repeat - 1;
            int numb = A.items[i];
            {
                while (n) {
                    A.remove(numb);
                    n--;
                }
            }
        }
    }
}