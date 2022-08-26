#pragma once

template<typename T>

class Stack
{
private:
    static const int DEFAULT_STEP = 3;

    int count;
    T* arr;
    int capacity;
    int step;

    bool isFull()
    {
        return this->count == this->capacity;
    }

    bool isMemoryNotAllocated()
    {
        return arr == nullptr;
    }

    void reallocateMemory()
    {
        if (arr == nullptr)
        {
            arr = new T[this->step];
            this->capacity = step;

            return;
        }

        this->capacity += this->step;

        T* temp = new T[this->capacity];
        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] arr;
        arr = temp;
    }

public:
    Stack() :
        count{},
        arr{ nullptr },
        capacity{},
        step{ Stack::DEFAULT_STEP }
    {}

    Stack(const Stack& obj) :
        count{ obj.count },
        arr{ new T[obj.capacity] },
        capacity{ obj.capacity },
        step{ obj.step }
    {
        for (int i{}; i < this->count; ++i)
            this->arr[i] = obj.arr[i];
    }

    Stack& operator=(const Stack& obj)
    {
        if (this == &obj)
            return *this;

        if (arr != nullptr)
            delete[] arr;

        this->count = obj.count;
        this->arr = new T[obj.capacity];
        this->capacity = obj.capacity;
        this->step = obj.step;

        for (int i{}; i < this->count; ++i)
            this->arr[i] = obj.arr[i];

        return *this;
    }

    void push(T val)
    {
        if (this->isFull() || this->isMemoryNotAllocated())
        {
            this->reallocateMemory();
        }

        arr[count] = val;

        ++count;
    }

    T pop()
    {
        if (!isEmpty())
        {
            --count;
            return this->arr[count];
        }

       // return -1;          // TODO: mini kostil... (change to throw exception)
    }

    T peak()
    {
        if (!isEmpty())
            return this->arr[count - 1];

        //return -1;          // TODO: mini kostil... (change to throw exception)
    }

    bool setStep(int step)
    {
        if (step < 1)
            return false;

        this->step = step;

        return true;
    }

    bool isEmpty()
    {
        return count == 0 || this->isMemoryNotAllocated();
    }

    int getCount()
    {
        return this->count;
    }

    int getCapacity()
    {
        return this->capacity;
    }

    void show()
    {
        std::cout << "capacity = " << this->capacity << '\n';
        std::cout << "count = " << this->count << '\n';
        std::cout << "stack:\n";
        for (int i{}; i < this->count; ++i)
            std::cout << this->arr[i] << '\n';
        std::cout << "\n\n";
    }

    ~Stack()
    {
        if (arr != nullptr)
            delete[] arr;
    }
};