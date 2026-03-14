#ifndef _MATRIX_GRAPH_
#define _MATRIX_GRAPH_

#include <iostream>
#include <vector>
#include <map>

namespace MatrixGraphModule
{
    template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
    class Graph
    {
    public:
        Graph(const V* vertexs, int n)
        {
            _vertex.reserve(n);
            for(int i = 0; i < n; i++)
            {
                _vertex.emplace_back(vertexs[i]);
                _vIndex[vertexs[i]] = i;
            }
            _matrix.resize(n);
            for(int i = 0; i < n; i++)
            {
                _matrix[i].resize(n, MAX_W);
            }
        }

        int GetIndex(const V& vertex)
        {
            auto it = _vIndex.find(vertex);
            if(it != _vIndex.end())
            {
                return it->second;
            }
            else{
                throw std::invalid_argument("invalid input");
                return -1;
            }
        }

        void AddEdge(const V& src, const V& dst, const W& weight)
        {
            int srcIndex = GetIndex(src);
            int dstIndex = GetIndex(dst);
            _matrix[srcIndex][dstIndex] = weight;
            if(Direction == false)
            {
                _matrix[dstIndex][srcIndex] = weight;
            }
        }

        void Print()
        {
            for(auto& e : _vertex)
            {
                std::cout << e << " -> " << _vIndex[e] << std::endl;
            }
            std::cout << std::endl;

            std::cout << "  ";
            for(int i = 0; i < _vertex.size(); i++)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            for(int i = 0; i < _matrix.size(); i++)
            {
                std::cout << i << " ";
                for(int j = 0; j < _matrix[i].size(); j++)
                {
                    if(_matrix[i][j] == MAX_W)
                    {
                        std::cout << "* ";
                    }
                    else{
                        std::cout << _matrix[i][j] << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
        ~Graph()
        {}
    private:
        std::vector<V> _vertex;
        std::map<V, int> _vIndex;
        std::vector<std::vector<W>> _matrix;
    };
}










# endif
