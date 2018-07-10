#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP


namespace data_structure{
    class DisjointSet{
        private:
            int N;
            int* track_arr;
            int* size;
            int root(int x);
        public:
            DisjointSet(int n);
            void _union(int a, int b);
            bool _find(int a, int b);
            ~DisjointSet();
    };
}


#endif