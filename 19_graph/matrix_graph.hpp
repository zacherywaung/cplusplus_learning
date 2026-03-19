#ifndef _MATRIX_GRAPH_
#define _MATRIX_GRAPH_

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include "union_find_set.hpp"

using namespace UnionFindSetModule;

namespace MatrixGraphModule
{
    template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
    class Graph
    {
    public:
        typedef Graph<V, W, MAX_W, Direction> Self;
        Graph() = default;
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

        void _AddEdge(int srcIndex, int dstIndex, const W& weight)
        {
            _matrix[srcIndex][dstIndex] = weight;
            if(Direction == false)
            {
                _matrix[dstIndex][srcIndex] = weight;
            }
        }

        void AddEdge(const V& src, const V& dst, const W& weight)
        {
            int srcIndex = GetIndex(src);
            int dstIndex = GetIndex(dst);
            _AddEdge(srcIndex, dstIndex, weight);
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

        void BFS(const V& src)
        {
            int srcIndex = GetIndex(src);
            std::queue<int> q;
            std::vector<bool> visited(_vertex.size(), false);
            q.push(srcIndex);
            visited[srcIndex] = true;
            int layer = 1;
            int layersize = 1;
            while(!q.empty())
            {
                std::cout << "Layer" << layer << ":" << std::endl;
                while(layersize--)
                {
                    int front = q.front();
                    q.pop();
                    std::cout << front << ":" << _vertex[front] << " ";
                    for(int i = 0; i < _vertex.size(); i++)
                    {
                        if(_matrix[front][i] != MAX_W && visited[i] == false)
                        {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
                std::cout << std::endl;
                layer++;
                layersize = q.size();
            }
            std::cout << std::endl;
        }


        void _DFS(int index, std::vector<bool>& visited)
        {
            for(int i = 0; i < _vertex.size(); i++)
            {
                if(_matrix[index][i] != MAX_W && visited[i] == false)
                {
                    std::cout << i << ":" << _vertex[i] << " ";
                    visited[i] = true;
                    _DFS(i, visited);
                }
            }
        }

        void DFS(const V& src)
        {
            int srcIndex = GetIndex(src);
            std::vector<bool> visited(_vertex.size(), false);
            visited[srcIndex] = true;
            std::cout << srcIndex << ":" << src << " ";
            _DFS(srcIndex, visited);
            std::cout << std::endl;
        }

        class Edge
        {
        public:
            W _w;
            int _src;
            int _dst;
        public:
            Edge(int src, int dst, W w)
                :_src(src)
                ,_dst(dst)
                ,_w(w)
            {}

            bool operator>(const Edge& o) const
            {
                return _w > o._w;
            }
        };

        W MinTreeKruskal(Self& minTree)
        {
            // init
            int n = _vertex.size();
            minTree._vertex = _vertex;
            minTree._vIndex = _vIndex;
            minTree._matrix.resize(n);
            for(int i = 0; i < n; i++)
            {
                minTree._matrix[i].resize(n, MAX_W);
            }
            // add all edge into min heap
            std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> minheap;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(i < j && _matrix[i][j] != MAX_W)
                    {
                        minheap.push(Edge(i, j, _matrix[i][j]));
                    }
                }
            }
            // greedy
            int count = 1;
            W ret = W();
            UnionFindSet ufs(n);
            while(!minheap.empty())
            {
                Edge e = minheap.top();
                minheap.pop();
                if(ufs.FindRoot(e._src) != ufs.FindRoot(e._dst))
                {
                    ufs.Union(e._src, e._dst);
                    ret += e._w;
                    minTree._AddEdge(e._src, e._dst, e._w);
                    count++;
                }
            }
            if(count == n)
            {
                return ret;
            }
            else{
                return W();
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










#endif
