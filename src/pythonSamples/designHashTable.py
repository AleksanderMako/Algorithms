from   hashTableBucket import Bucket
class MyHashMap(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.TableSize=2069
        self.Table=[Bucket() for i in range(self.TableSize)]
        

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: None
        """
        idx = self.getIndex(key)
        # print("Inserting value "+ str(value)+" at index " + str(idx))

        self.Table[idx].update(key,value)
        # print("The inserted value is " + str(self.Table[idx]))

        

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        idx = self.getIndex(key)
        # print("Index is "+ str(idx))
        return self.Table[idx].find(key)
        

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: None
        """
        idx = self.getIndex(key)
        self.Table[idx].remove(key)
        

    def getIndex(self,key):
        return key % self.TableSize
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)