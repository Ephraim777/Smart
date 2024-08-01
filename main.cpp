#include<iostream>
using namespace std;

template<typename T>
class SmartArray
{
    T * m_ptrArr;
    size_t m_size;
    size_t m_capacity;
public:
    SmartArray(size_t count):m_ptrArr(new T[count]),m_size(0), m_capacity(count){}
    ~SmartArray()
    {
        delete [] m_ptrArr;
        m_ptrArr = nullptr;
    }
    T&operator [] (int index)
    {
        if(index >= m_size || index < 0)
        {
            throw std::out_of_range("Invalid index");
        }
        return m_ptrArr[index];
    }

    void push_back(const T & elem)
    {
        if (m_size < m_capacity)
        {
            m_ptrArr[m_size] = elem;

        }
        else
        {
            if(!m_capacity)
            {
                m_capacity = 1;
            }
            m_capacity *= 2;
            T * NewPtr = new T[m_capacity];
            for (size_t i= 0; i< m_size; i++)
            {
                NewPtr[i] = m_ptrArr[i];

            }

            delete [] m_ptrArr;
            m_ptrArr = NewPtr;
            NewPtr = nullptr;
            m_ptrArr[m_size] = elem;
        }
        m_size++;
    }
    void Print()
    {
        for(size_t i = 0; i< m_size; i++)
        {
            std::cout << m_ptrArr[i] << " " ;
        }
    }

    SmartArray& operator = (SmartArray & arr)
    {
        if(this != &arr)
        {
            if (m_ptrArr!= nullptr)
            {

                delete [] m_ptrArr;
                m_ptrArr = nullptr;
            }
            m_ptrArr = new T[arr.m_capacity];
            m_capacity = arr.m_capacity;
            m_size = arr.m_size;
            for (size_t i = 0; i< m_size; i++)
            {
                m_ptrArr[i] = arr[i];
            }}
        return *this;

    }
};

int main()
{

    try {

        SmartArray <int> arr(0);

        arr.push_back(9);
        arr.push_back(8);
        // arr.Print();
        // std::cout << arr[0];

        SmartArray <int> arr1(3);

        arr1.push_back(98);
        arr1.push_back(897);

        arr = arr1;
        arr.Print();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}