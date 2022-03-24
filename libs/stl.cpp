// List
list<T> l;

l.push_front(i); // void
l.push_back(i); // void
l.pop_front(); // T
l.pop_back(); // T
l.empty(); // bool
l.front(); // T
l.back(); // T
l.sort(compareFunc);

// Map
map<K, V> m;
m[k] = v; // insert
for (auto [k, v] : m) {
} // iteration
m.find(k) == m.end(); // check m has k
