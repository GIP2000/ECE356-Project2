#include "heap.h"
#include "hash.h"
#include <vector>
#include <bits/stdc++.h>
#include <iostream> 

using namespace std;
heap::heap(int capacity){
    this->capacity = capacity;
    this->data = vector<heap::heapItem>(capacity+1);
    this->hashmap = hashTable(capacity); 
}
int heap::insert(const std::string &id, int key, void *pv){
    if(this->capacity == this->lastIndex) return 1; 
    if(this->hashmap.contains(id)) return 2; 

    for(int i = this->lastIndex + 1; i > 0; i /= 2){
        if(checkIfValid(i,key) == 0){
            this->data[i].key = key;
            this->data[i].id = id; 
            this->data[i].pv = pv; 
            this->data[i].index = i; 
            this->hashmap.insert(id,&data[i]); 
            this->lastIndex++; 
            return 0;
        }
        data[i] = data[i/2];
        data[i].index/=2; 
    }
    return -1; // unexpected error should never occur; 

}
int heap::setKey(const std::string &id, int key){
    bool found = false; 
    heapItem* item = (heapItem*)this->hashmap.getPointer(id,&found);
    if(!found) return 1; 

    int i = item->index; 
    item->key = key; 
    while(true){
        switch(checkIfValid(i,key)){
            case 0: 
                this->data[i].index = i; // idt I Need up update hashTable but I should check
                return 0;
            case 1:
                data[i] = data[i/2];
                data[i].index/=2; 
                i/=2; 
                break;
            case 2: 
                this->data[i] = this->data[i*2];
                this->data[i].index*=2;
                i*=2; 
                break;
            case 3:
                this->data[i] = this->data[i*2+1];
                this->data[i].index=this->data[i].index*2+1;
                i = i*2 +1; 
                break;
        }
    }


}
int heap::deleteMin(std::string *pId, int *pKey , void *ppData ){
    if(this->lastIndex == 0) return 1; 

    heapItem min = this->data[1]; 
    if(pId != nullptr) *pId = min.id; 
    if(pKey != nullptr) *pKey = min.key;
    if(ppData != nullptr) ppData = min.pv;
    this->hashmap.remove(min.id); 

    heapItem bot = this->data[this->lastIndex]; 
    const int key = bot.key; 
    bool addOne = false; 
    this->lastIndex--; 
    for(int i = 1; i<this->lastIndex+1; i*=2){
        if(addOne){
            i++;
            addOne = false;
        } 
        switch(checkIfValid(i,key)){
            case 0: 
                this->data[i] = bot; 
                this->data[i].index = i; // idt I Need up update hashTable but I should check
                
                return 0;
            case 2: 
                this->data[i] = this->data[i*2];
                this->data[i].index*=2;
                break;
            case 3:
                this->data[i] = this->data[i*2+1];
                this->data[i].index=this->data[i].index*2+1;
                addOne = true;
                break;
        }

    }
    return 0; // should only happen if the array has only 1 item in it
    

}
int heap::remove(const std::string &id, int *pKey, void *ppData){
    if(this->setKey(id,this->data[1].key-1) == 1) return 1;
    return this->deleteMin(nullptr,pKey,ppData);  
}

int heap::checkIfValid(int index, int key, bool print){
    if(print) cout << "key = " << key << "\n"; 
    int parentKey = this->data[index/2].key;
    if(print)cout << "parentKey = " << parentKey << "\n"; 
    int leftChild = this->data[index*2].key;
    if(print)cout << "leftChild = " << leftChild << "\n"; 
    int rightChild = this->data[index*2 +1].key;
    if(print)cout << "rightChild = " << rightChild << "\n"; 


    if(index/2 > 0 && key < parentKey) return 1;
    if((index*2) <= this->lastIndex && key > leftChild && leftChild < rightChild) return 2;
    if((index*2 + 1) <= this->lastIndex && key > rightChild) return 3;
    return 0; 
}