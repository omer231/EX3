/*-*-*-*PART*A*-*-*-*/
class BadInput : public std::exception
{};

template<class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if (start < 0 || start >= vec.size() || stop < 0 || stop > vec.size() || step <= 0)
	{
        throw BadInput();
    }
    std::vector<T> newVec;

    for (int i = start; i < stop; i += step)
	{
        T value;
        value = vec[i];
        newVec.push_back(value);
    }
    return newVec;
}

/*-*-*-*PART*B*-*-*-*/

class A {
public:
    std::vector<std::shared_ptr<int>> values;

    void add(int x)
    {
        std::shared_ptr<int> ptr(new int(x));
        values.push_back(ptr);
    }
};