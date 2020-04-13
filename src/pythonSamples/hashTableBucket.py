class Bucket:
    def __init__(self):
        self.bucket=[]
    
    def update(self,key,value):
        exist=False
        for index ,kv in enumerate(self.bucket):
            if key == kv[0]:
                self.bucket[index]=(key,value)
                exist=True
                break
        if not exist:
            self.bucket.append((key,value))
    
    def find(self,key):

        for (k,v)in self.bucket:
            if k == key:
                return v
        return -1

    def remove(self,key):
        for index,kv in enumerate(self.bucket):
            if kv[0]==key:
                del self.bucket[index]