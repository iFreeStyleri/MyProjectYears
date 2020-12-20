
template <typename T>

class MyList
{
private:
	int i = 0;
	T* array = 0;
public:

	void BSort()
	{
		int max = sizeof(array) / sizeof(*array);
		for (int i = 0; i < max; ++i) {
			bool flag = true;
			for (int j = 0; j < max - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					flag = false;
					swap(array[j], array[j + 1]);
				}
			}
			if (flag)
				break;
		}
	}

	void pushBack(T num)
	{
		if (i == 0)
		{
			this->array = (T*)malloc(sizeof(num));
			*(array + i) = num;
		}
		else
		{
			int j = 0;
			bool protect = false;
			while (!protect)
			{
				if (array)
				{
					T* buffer = (T*)malloc((i + 1) * sizeof(T));
					if (buffer)
					{
						for (j = 0; j <= i; ++j)
						{
							*(buffer + j) = *(array + j);
						}
						free(array);
						*(buffer + i) = num;
						array = (T*)malloc((i + 1) * sizeof(T));
						for (j = 0; j <= i; ++j)
						{
							*(array + j) = *(buffer + j);
						}
						free(buffer);
						protect = true;
					}
				}
				else
					array = (T*)malloc((i + 1) * sizeof(T));

			}

		}
		++i;
	}

	void pushBack(T* num, const int size)
	{
		for (int s = 0; s < size; ++s)
		{
			pushBack(*(num + s));
		}
	}

	void pushBetween(T num, int location)
	{
		bool protect = false, prod = false;
		if (i == 0)
		{
			array = (T*)malloc(sizeof(num));
			*(array + i) = num;
		}
		else
		{
			int j = 0;
			while (!protect)
			{
				if (array)
				{
					T* buffer = (T*)malloc((i + 1) * sizeof(T));
					if (buffer) {
						for (j = 0; j <= i; ++j)
						{
							if (prod == false) {
								if (location != j) 
									*(buffer + j) = *(array + j);
								else if (location == j)
								{
									*(buffer + j) = num;
									prod = true;
								}
							}
							else
								*(buffer + j) = *(array + (j - 1));
						}
						free(array);
						array = (T*)malloc((i + 1) * sizeof(T));
						for (j = 0; j <= i; ++j)
						{
							array[j] = *(buffer + j);
						}
						free(buffer);
						protect = true;
					}
				}
				else
				{
					array = (T*)malloc((i + 1) * sizeof(T));
				}
			}
		}
		++i;
	}

	void pushBetween(T* num, const int size, int firstLocation)
	{
		for (int j = 0; j < size; ++firstLocation, ++j)
		{
			pushBetween(num[j], firstLocation);
		}
	}

	void SetArray(T num, int location)
	{
		if (location >= 0 && location <= i)
			*(array + location) = num;
	}

	void deleteArray()
	{
		if (array)
		{
			free(array);
			i = 0;
			array = NULL;
		}
	}

	T GetArray(int choice)
	{
		if (choice >= 0 && choice <= i)
			return *(array + choice);
		else
			return 0;
	}

	int Capacity()
	{
		return i;
	}

	const char* type()
	{
		return typeid(*array).name();
	}
};