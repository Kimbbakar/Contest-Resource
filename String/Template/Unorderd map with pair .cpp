struct pair_hash {
    std::size_t operator () (const std::pair<long long,long long> &p) const {
        auto h1 = std::hash<long long>{}(p.first);
        auto h2 = std::hash<long long>{}(p.second);


        return (h1 << 30 ) ^ h2;  
    }
}; 

unordered_map<Vote, int, pair_hash>maps;