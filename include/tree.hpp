#include <iostream>
#include <sstream>
#include <string>

class tree_t
{
private:
    struct node_t
    {
        node_t* left;
        node_t* right;
        int value;
    };

private:
    node_t* root_;

public:
    tree_t()
    {
        root_ = nullptr;
    }

    void insert(int value)
    {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->value = value;
            root_->left = nullptr;
            root_->right = nullptr;
        }
        else
        {
            node_t* run_ = root_;
            while (run_ != nullptr)
            {
                if (value < run_->value)
                {
                    if (run_->left == nullptr)
                    {
                        run_->left = new node_t;
                        run_ = run_->left;
                        run_->value = value;
                        run_->left = nullptr;
                        run_->right = nullptr;
                        return;
                    }
                    else
                    {
                        run_ = run_->left;
                    }
                }
                else if (value >= run_->value)
                {
                    if (run_->right == nullptr)
                    {
                        run_->right = new node_t;
                        run_ = run_->right;
                        run_->value = value;
                        run_->left = nullptr;
                        run_->right = nullptr;
                        return;
                    }
                    else
                    {
                        run_ = run_->right;
                    }
                }
            }
        }
    }

    bool find(int value) const
    {
        if (root_ == nullptr)
        {
            return false;
        }
        else
        {
            node_t* run_ = root_;
            while (run_ != nullptr)
            {
                if (run_->value == value)
                {
                    return true;
                }
                else if (run_->value < value)
                {
                    run_ = run_->right;
                }
                else if (run_->value > value)
                {
                    run_ = run_->left;
                }
            }
            return false;
        }
    }

    node_t* root() const
    {
        return root_;
    }

    ~tree_t()
    {
        if (root_ != nullptr)
        {
            del(root_);
        }
    }

    void del(node_t* run_)
    {
        if (run_ != nullptr)
        {
            if (run_->left != nullptr)
            {
                del(run_->left);
            }
            if (run_->right != nullptr)
            {
                del(run_->right);
            }
            delete run_;
        }
    }

    void print(std::ostream& stream, node_t* run_, size_t u) const
    {
        if (run_->right != nullptr)
        {
            u++;
            print(stream, run_->right, u);
            u--;
        }
        for (size_t k = 0; k < u; k++)
        {
            stream << "--";
        }
        stream << run_->value << std::endl;
        if (run_->left != nullptr)
        {
            u++;
            print(stream, run_->left, u);
            u--;
        }
    }
};

bool read(tree_t& tree, std::istream& stream)
{
    char op;
    int value;
    if (stream >> op && (op == '=' || op == '+' || op == '?' || op == 'q'))
    {
        if (op == '=')
        {
            tree.print(std::cout, tree.root(), 1);
        }
        else if (op == 'q')
        {
            return false;
        }
        else if ((op == '+' || op == '?') && stream >> value)
        {
            if (op == '+')
            {
                tree.insert(value);
            }
            else if (op == '?')
            {
                std::cout << tree.find(value) << std::endl;
            }
        }
    }
    return true;
}
