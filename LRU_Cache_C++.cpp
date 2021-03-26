#include <unordered_map>
#include <iostream>

class LRUCache{
public:
	LRUCache(int capacity){
		_capacity = capacity;
	}
	
	int get(int key){
		auto item = _cache.find(key);
		if (item == cache.end()){
			return -1;
		}
		return it->second.first;
	}

	void set(int key, int value){
		auto item = _cache.find(key);
		if(item != _cache.end()){
			use(item);
			_cache[key] = { value, _lru.begin()};
			return;
		}
		if(_cache.size() == _capacity){
			_cache.erase(lru.back()));
			_lru.popback();
		}
		_lru.push_front(key);
		_cache.insert({key, {value, _lru.being()}});
	}
	

	void use(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator& it){
		_lru.erase(it->second.second);
		_lru.push_front(it->first);
		it->second.second = _lru.begin();
	}

private:
	int _intcapacity;
	std::unordered_map<int, std::pair<int, std::list<int>::iterator>>:: _cache;
	std::list<int> _lru;

int main(){
	/*
	LRUCache * cache = new LRUCache(2);
	cache->set(1,1);
	cache->set(2,2);
	std::cout<<cache-get(1)<<std::endl;
	cache->set(3,3);
	std::cout<<cache-get(2)<<std::endl;
	*/
}

/*
1:1
3:3

1, -1
*/