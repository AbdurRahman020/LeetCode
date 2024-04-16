from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last = False)

if __name__ == '__main__':
    myLRUCache = LRUCache(2)
    myLRUCache.put(1,1)
    myLRUCache.put(2,2)
    print('get:', myLRUCache.get(1))
    myLRUCache.put(3,3)
    print('get:', myLRUCache.get(2))
    myLRUCache.put(4,4)
    print('get:', myLRUCache.get(1))
    print('get:', myLRUCache.get(3))
    print('get:', myLRUCache.get(4))