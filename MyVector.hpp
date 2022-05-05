template <typename T>
void MySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
MyVector<T>::MyVector() {
    reserved_size = 0;
    data_size = 0;
    m_data = new T[reserved_size];
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source) {
    //Check if the size of the array is the same
    if(reserved_size != source.reserved_size) {
        reserved_size = source.reserved_size;
        delete[] m_data;
        m_data = new T[source.reserved_size];
    }
    for(int i = 0; i < reserved_size; i++) {
        m_data[i] = source.m_data[i];
    }

    data_size = source.data_size;
    return *this;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> & source) {
    m_data = new T[source.reserved_size];
    data_size = source.data_size;
    reserved_size = source.reserved_size;

    for(int i = 0; i < reserved_size; i++)
        m_data[i] = source.m_data[i];
}


template <typename T>
T & MyVector<T>::at(int index)
{
    if (index > reserved_size) {
        throw std::out_of_range ("out of range");
    } 
    return m_data[index];
}

template <typename T>
T & MyVector<T>::operator[](int i) {
    return m_data[i];
}

template<typename T>
int MyVector<T>::capacity() {return reserved_size;}

template<typename T>
int MyVector<T>::size() {return data_size;}

template <typename T>
T & MyVector<T>::front() {
    return *m_data;
}

template <typename T>
T & MyVector<T>::back() {
    return (m_data[data_size-1]);
}

template <typename T>
void MyVector<T>::reserve(int new_cap) {
    if (reserved_size == 0) {
        reserved_size++;
        T * t = new T[reserved_size];
        delete[] m_data;
        m_data = t;
    } else if (new_cap > reserved_size) {
        T * p = new T[new_cap];
        for(int i = 0; i < data_size; i++)
            p[i] = m_data[i];
        delete[] m_data;
        m_data = p;   
        reserved_size = new_cap;
    } else {
        cout << "new_cap is not greater than reserved size" << endl;
    }
}

template <typename T>
void MyVector<T>::shrink_to_fit() {
    T * p = new T[data_size*2];

    for(int i = 0; i < data_size; i++)
        p[i] = m_data[i];

    delete[] m_data;
    m_data = p;
    reserved_size = data_size*2;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value) {
    for(int i = 0; i < count; i++)
        push_back(value);
}

template <typename T>
void MyVector<T>::clear() {
    data_size = 0;
    reserved_size = 0;
    delete[] m_data;
    m_data = nullptr;
}

template <typename T>
void MyVector<T>::push_back(const T & x) {
    if (reserved_size == 0) reserve(1);
    m_data[data_size] = x;
    data_size++;
    if (data_size == reserved_size) {
        reserve(reserved_size + 1);
    }
}

template <typename T>
void MyVector<T>::pop_back() {
    erase(data_size);
}

template <typename T>
void MyVector<T>::insert(int i, const T &x) {
    if((data_size+2)==reserved_size)
        reserve(1);
    for(int r = data_size; r > i-1; r--)
        m_data[r] = m_data[r-1];
    m_data[i] = x;
    data_size++;
}

template <typename T>
void MyVector<T>::erase(int i) {
    if (i < 0 || i > data_size) {
        throw "index error";
    } else {
        if (data_size > 1) {
            for(int r = i; r < data_size; r++)
                m_data[r] = m_data[r+1];
            m_data[data_size] = NULL;
        } else {
            m_data[0] = NULL;
        }
        data_size--;
        if (data_size <= (reserved_size/4))
            shrink_to_fit();
    }
}
