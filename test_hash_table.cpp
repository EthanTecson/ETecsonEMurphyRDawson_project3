//=================================
// Ethan Tecson, Eleanor Murphy, Ryan Dawson
// test_hash_table.cpp
// Feb 2024
// This file contains unit testing for all methods in Element and HashTable
//=================================

#include <iostream>
#include "hash_table.cpp"
using namespace std;

void test_get_key()
{
    try
    {
        // Testing with ints
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
        // Int copy constructor with get_key
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
        // String copy constructor with get_key
        Element<string> copyStrE(strE);
        if (copyStrE.get_key() != 5)
        {
            cout << "Incorrect result from copy constructor and get key. Expected 5 but got : " << copyStrE.get_key() << endl;
        }

        // Testing with floats
        Element<float> emptyFl;
        if (emptyFl.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << emptyFl.get_key() << endl;
        }
        Element<float> flE(0.1, 3);
        if (flE.get_key() != 3)
        {
            cout << "Incorrect result from get key. Expected 3 but got : " << flE.get_key() << endl;
        }
        // Float copy constructor with get_key
        Element<float> copyFlE(flE);
        if (copyFlE.get_key() != 3)
        {
            cout << "Incorrect result from copy constructor get key. Expected 3 but got : " << copyFlE.get_key() << endl;
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
        // Testing ints
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
        // Int copy constructor
        Element<int> f(e);
        if (e.get_data() != f.get_data())
        {
            cout << "Incorrect result from copy constructor and get data. Expected 6 but got : " << f.get_data() << endl;
        }

        // Testing strings
        Element<string> emptyStrE;
        if (emptyStrE.get_data() != "")
        {
            cout << "Incorrect result from get data. Expected the empty string for an empty element but got : " << emptyStrE.get_data() << endl;
        }
        Element<string> strE("hello", 5);
        if (strE.get_data() != "hello")
        {
            cout << "Incorrect result from get data. Expected 'hello' but got : " << strE.get_data() << endl;
        }
        // String copy constructor
        Element<string> strF(strE);
        if (strE.get_data() != strF.get_data())
        {
            cout << "Incorrect result from get data. Expected 'hello' but got : " << strF.get_data() << endl; 
        }

        // Testing with floats
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
        // Float copy constructor
        Element<float> flHt_copy(flHt);
        if (abs(flHt.get_data() - 0.1) != abs(flHt_copy.get_data() - 0.1))
        {
            cout << "Incorrect result from get data. Expected 0.1 but got : " << flHt_copy.get_data() << endl;
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
        // Inserting into empty int HashTable
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected an empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
        // Inserting into empty string HashTable
        HashTable<string> emptyStrHt(0);
        emptyStrHt.insert("hello", 5);
        if (emptyStrHt.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected an empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
        // Inserting into empty float HashTable
        HashTable<float> emptyFl(0);
        emptyFl.insert(0.1, 3);
        if (emptyFl.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected an empty string But got\n\n"
                 << emptyFl.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try
    {
        // Inserting int
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
        // Inserting int again (new element should be at head)
        ht.insert(1, 21);
        if (ht.to_string() != "0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of inserting into table" << endl;
        }
        // Inserting string
        HashTable<string> strHt(3);
        strHt.insert("hello", 5);
        if (strHt.to_string() != "0: \n1: \n2: (hello,5) \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (hello,5) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
        // Inserting string again (new element should be at head)
        strHt.insert("hi", 53);
        if (strHt.to_string() != "0: \n1: \n2: (hi,53) (hello,5) \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: (hello,5) (hi,53) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
        // Inserting float 
        HashTable<float> flHt(3);
        flHt.insert(0.1, 3);
        if (flHt.to_string() != "0: (0.1,3) \n1: \n2: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: (0.1,3) \n1: \n2: \n\nBut got\n\n"
                 << flHt.to_string() << endl;
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
        // Attempting to remove an element from empty int table
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected ann empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
        // Attempting to remove an element from empty string table
        HashTable<string> emptyStrHt(0);
        emptyStrHt.remove(4);
        if (emptyStrHt.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << emptyStrHt.to_string() << endl;
        }
        // Attempting to remove an element from empty float table
        HashTable<float> emptyflHt(0);
        emptyflHt.remove(3);
        if (emptyflHt.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << emptyflHt.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try
    {
        // Attempting to remove element whose key does not exist in int HT
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if (ht.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht.to_string() << endl;
        }
        // Attempting to remove element whose key does not exist in string HT
        HashTable<string> strHt(3);
        strHt.insert("hello", 5);
        strHt.remove(4);
        if (strHt.to_string() != "0: \n1: \n2: (hello,5) \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: (hello,5) \n\nBut got\n\n"
                 << strHt.to_string() << endl;
        }
        // Attempting to remove element whose key does not exist in float HT
        HashTable<float> flHt(3);
        flHt.insert(1.4, 3);
        flHt.remove(5);
        if (flHt.to_string() != "0: (1.4,3) \n1: \n2: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n0: (1.4,3)\n1: \n2: \n\nBut got\n\n"
                 << flHt.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try
    {
        // Attempting to remove element in int HT
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }
        // Attempting to remove element in string HT
        HashTable<string> strHt2(3);
        strHt2.insert("hello", 5);
        strHt2.remove(5);
        if (strHt2.to_string() != "0: \n1: \n2: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n\nBut got\n\n"
                 << strHt2.to_string() << endl;
        }
        // Attempting to remove element in float HT
        HashTable<float> flHt(3);
        flHt.insert(1.4, 3);
        flHt.remove(3);
        if (flHt.to_string() != "0: \n1: \n2: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n\nBut got\n\n"
                 << flHt.to_string() << endl;
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
        // Testing for member in empty int HT
        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
        // Testing for member in empty string HT
        HashTable<string> emptyStrHt(0);
        if (emptyStrHt.member("hello", 5))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
        // Testing for member in empty float HT
        HashTable<float> emptyFlHt(0);
        if (emptyFlHt.member(0.2, 3))
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
        // Testing for member in int HT
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

        // Testing for member in string HT
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

        // Testing for member in float HT
        HashTable<float> flHt(3);
        flHt.insert(0.1, 3);
        if (!flHt.member(0.1, 3))
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (flHt.member(0.2, 3))
        {
            cout << "Incorrect membership in table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}

void test_get_slot_count()
{
    try
    {
        HashTable<int> ht(4);
        ht.insert(3, 5);
        ht.insert(3, 10);
        ht.insert(3, 4);
        ht.insert(3, 2);

        // Testing on filled slots in int HT
        if (ht.get_slot_count(0) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << ht.get_slot_count(0) << endl;
        }
        if (ht.get_slot_count(1) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << ht.get_slot_count(1) << endl;
        }
        if (ht.get_slot_count(2) != 2)
        {
            cout << "Incorrect result from get_slot_count. Expected 2 but got : " << ht.get_slot_count(2) << endl;
        }
        // Testing on empty slot in int HT
        if (ht.get_slot_count(3) != 0)
        {
            cout << "Incorrect result from get_slot_count. Expected 0 but got : " << ht.get_slot_count(3) << endl;
        }
        
        HashTable<string> strHt(4);
        strHt.insert("hello", 5);
        strHt.insert("world", 10);
        strHt.insert("Truex", 4);
        strHt.insert("Kretchmar", 2);

        // Testing on filled slots in string HT
        if (strHt.get_slot_count(0) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << strHt.get_slot_count(0) << endl;
        }
        if (strHt.get_slot_count(1) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << strHt.get_slot_count(1) << endl;
        }
        if (strHt.get_slot_count(2) != 2)
        {
            cout << "Incorrect result from get_slot_count. Expected 2 but got : " << strHt.get_slot_count(2) << endl;
        }
        // Testing on empty slot in int HT
        if (strHt.get_slot_count(3) != 0)
        {
            cout << "Incorrect result from get_slot_count. Expected 0 but got : " << strHt.get_slot_count(3) << endl;
        }

        HashTable<float> flHt(4);
        flHt.insert(0.1, 5);
        flHt.insert(0.2, 10);
        flHt.insert(0.3, 4);
        flHt.insert(0.4, 2);

        // Testing on filled slots in float HT
        if (flHt.get_slot_count(0) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << flHt.get_slot_count(0) << endl;
        }
        if (flHt.get_slot_count(1) != 1)
        {
            cout << "Incorrect result from get_slot_count. Expected 1 but got : " << flHt.get_slot_count(1) << endl;
        }
        if (flHt.get_slot_count(2) != 2)
        {
            cout << "Incorrect result from get_slot_count. Expected 2 but got : " << flHt.get_slot_count(2) << endl;
        }
        // Testing on empty slot in float HT
        if (flHt.get_slot_count(3) != 0)
        {
            cout << "Incorrect result from get_slot_count. Expected 0 but got : " << flHt.get_slot_count(3) << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to calculate the number of items in a given slot" << e.what() << endl;
    }
}

int main()
{
    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();
    test_get_slot_count();

    cout << "Testing completed" << endl;

    return 0;
}