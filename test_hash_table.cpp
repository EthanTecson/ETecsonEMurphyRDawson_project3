//
//  test_hashtable_example.cpp
//  CS 271 Hash Table Project: Example Test File
//
//  Created by Dr. Stacey Truex
//

#include <iostream>
#include "hash_table.cpp"

using namespace std;

void test_get_key()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty_elem.get_key() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }
        Element<int> f(e);
        if (e.get_key() != f.get_key())
        {
            cout << "Incorrect result from copy constructor and get key. Expected 6 but got : " << f.get_key() << endl;
        }

        // Testing with strings
        Element<string> emptyStrE;
        if (emptyStrE.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << emptyStrE.get_key() << endl;
        }
        Element<string> strE("hello", 5);
        if (strE.get_key() != 5)
        {
            cout << "Incorrect result from get key. Expected 5 but got : " << strE.get_key() << endl;
        }

        // Testing with floats
        Element<float> emptyFl;
        if (emptyFl.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << emptyFl.get_key() << endl;
        }
        Element<float> flHt(0.1, 3);
        if (flHt.get_key() != 3)
        {
            cout << "Incorrect result from get key. Expected 3 but got : " << flHt.get_key() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << empty_elem.get_data() << endl;
        }
        Element<int> e(10, 6);
        if (e.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got : " << e.get_data() << endl;
        }
        Element<string> emptyStrE;
        if (emptyStrE.get_data() != "")
        {
            cout << "Incorrect result from get key. Expected the empty string for an empty element but got : " << emptyStrE.get_key() << endl;
        }
        Element<string> strE("hello", 5);
        if (strE.get_data() != "hello")
        {
            cout << "Incorrect result from get data. Expected hello but got : " << strE.get_data() << endl;
        }

        Element<float> emptyFl;
        if (emptyFl.get_data() != 0.0)
        {
            cout << "Incorrect result from get data. Expected 0.0 but got : " << emptyFl.get_data() << endl;
        }
        Element<float> flHt(0.1, 3);
        if (abs(flHt.get_data() - 0.1) < 1e-9)
        {
            cout << "Incorrect result from get data. Expected 0.1 but got : " << flHt.get_data() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
        HashTable<string> emptyStrHt(0);
        emptyStrHt.insert("hello", 5);
        if (emptyStrHt.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }

        HashTable<float> emptyFl(0);
        emptyFl.insert(0.1, 3);
        if (emptyFl.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << emptyFl.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table" << endl;
        }

        HashTable<string> strHt(3);
        strHt.insert("hello", 5);
        if (strHt.to_string() != "0: \n1: \n2: (hello,5) \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (hello,5) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
        strHt.insert("hi", 53);
        if (strHt.to_string() != "0: \n1: \n2: (hi,53) (hello,5) \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (hello,5) (hi,53) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }

        HashTable<string> emptyStrHt(0);
        emptyStrHt.remove(4);
        if (emptyStrHt.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << emptyStrHt.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }

        HashTable<string> strHt(3);
        strHt.insert("hello", 5);
        strHt.remove(4);
        if (strHt.to_string() != "0: \n1: \n2: (hello,5) \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: (hello,5) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }

        HashTable<string> strHt2(3);
        strHt2.insert("hello", 5);
        strHt2.remove(5);
        if (strHt2.to_string() != "0: \n1: \n2: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n\nBut got\n\n"
                 << strHt2.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

void test_member()
{
    try
    {
        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
        HashTable<string> emptyStrHt(0);
        if (emptyStrHt.member("hello", 5))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.member(11, 6))
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (!ht.member(10, 6))
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        HashTable<string> strHt(3);
        strHt.insert("hello", 5);
        if (!strHt.member("hello", 5))
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (strHt.member("hi", 5))
        {
            cout << "Incorrect membership in table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}

int main()
{
    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();

    cout << "Testing completed" << endl;

    return 0;
}