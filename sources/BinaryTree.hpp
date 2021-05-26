#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace ariel
{
    template <class T>
    class BinaryTree
    {
        struct Node
        {
            T data;
            Node *left = nullptr;
            Node *right = nullptr;

            Node(T d) : data(d), left(nullptr), right(nullptr) {}
        };
        
        Node *root;

        class IteratorByOrder
        {
        private:
            Node *tmp;

        public:
            IteratorByOrder(Node *ptr = nullptr)
                : tmp(ptr)
            {
            }

            T &operator*() const
            {
                return tmp->data;
            }

            T *operator->() const
            {
                return &(tmp->data);
            }

            IteratorByOrder &operator++()
            {
                
                return *this;
            }
            
            const IteratorByOrder operator++(int)
            {
                IteratorByOrder tmp = *this;
                return tmp;
            }

            bool operator==(const IteratorByOrder &rhs) const
            {
                return tmp == rhs.tmp;
            }

            bool operator!=(const IteratorByOrder &rhs) const
            {
                return tmp != rhs.tmp;
            }
        }; 

    public:
        BinaryTree<T>()
        {
            root = nullptr;
        }

        BinaryTree<T> add_root(const T &data)
        {
            return *this;
        }

        BinaryTree<T> add_left(const T &data, const T &left)
        {
            return *this;
        }

        BinaryTree<T> add_right(const T &data, const T &right)
        {
            return *this;
        }

        IteratorByOrder begin_preorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder end_preorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder begin_inorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder end_inorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder begin_postorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder end_postorder()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder begin()
        {
            return IteratorByOrder{root};
        }

        IteratorByOrder end()
        {
            return IteratorByOrder{root};
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            os << "This is a Binary Tree";
            return os;
        }
    }; 
} 