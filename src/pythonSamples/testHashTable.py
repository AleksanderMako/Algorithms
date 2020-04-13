from designHashTable import MyHashMap

hashMap  = MyHashMap()

hashMap.put(1, 1)        
hashMap.put(2, 2)         
print("Value is " + str(hashMap.get(2)))
print(hashMap.get(3))

hashMap.put(2, 1)
print("New Value  is " + str(hashMap.get(2)))
