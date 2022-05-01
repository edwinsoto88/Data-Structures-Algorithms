/*
    Name: Edwin Soto-Villela
    Description: For our chaining hash table, all of the elements are stored in the hash table.
    So the table never becomes full and can be linked to the same index/bucket. With chaining, you
    have to worry about the table becoming full or not, but  some space may be wasted as they're not used.
*/

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <stdexcept>
using namespace std;

int table_size = 10000; // set the table size to 10,000

class hashTable
{
    list<string> *table;
    int bucket;

public:
    hashTable(int x);
    int hashFunction(int);
    bool insertItem(string, int);
    string findItem(int);
    bool removeItem(int);
    void printHashTable();
};

/*
    The hash table funtion initializes an empty hash table with the size
    of table size(10,000).
*/
hashTable::hashTable(int x)
{
    this->bucket = x;
    table = new list<string>[table_size];
}

/*
    This function generates a hash everytime we want to insert
    a value in the hash table. It takes in a key and hashes it based off
    the size of the table. In thsi case key % table_size -> 90 % 10,000 = index 90
*/
int hashTable::hashFunction(int key)
{
    return key % bucket;
}

/*
    Insert function that inserts a key and value into an empty slot, if the slot already exists, attach on to it
*/
bool hashTable::insertItem(string value, int key)
{
    int index = hashFunction(key);
    table[index].push_back(value);
    cout << "Item: " << value << " has been inserted in index (" << index << ")" << endl;
    return true;
}

/*
    Function that removes data based on the given key entered and
    returns 'The item wasn't in the list' if it wasn't found.
*/
bool hashTable::removeItem(int key)
{
    int index = hashFunction(key);

    list<string>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
    {
        table[index].erase(i);
        cout << "Key " << key << " has been removed." << endl;
        return true;
    }
    return false;
}

/*
    Function that searches for the key, and if the entered key matches
    with the key in the table, return the vlaue associated with that key.
    Else, return "The key isn't in the list".
*/
string hashTable::findItem(int key)
{
    int index = hashFunction(key);
    bool flag = false;

    list<string>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++)
    {
        return *it;
    }
}

/*
    Prints out our indexes and values associated with the vlaues entered
    for our open addressing table.
*/
void hashTable::printHashTable()
{
    ofstream myfile("result_hash.txt");
    for (int i = 0; i < bucket; i++)
    {
        myfile << "key: " << i;
        for (auto x : table[i])
            myfile << " --> " << x;
        myfile << endl;
    }
}

int main()
{
    int key_answer;
    hashTable h1(table_size);

    h1.insertItem("Edwin", 7);
    h1.insertItem("Jim", 206);
    h1.insertItem("Gordon", 555);
    h1.insertItem("Soto", 940);
    h1.insertItem("David", 941);
    h1.insertItem("Maci", 86);
    h1.insertItem("Inigo", 665);
    h1.insertItem("Brandon", 942);
    h1.insertItem("Branden", 944);
    h1.insertItem("Dev", 33);
    h1.insertItem("Zachary Patton", 3482);
    h1.insertItem("Callum Farmer", 8250);
    h1.insertItem("Ariana Reed", 5077);
    h1.insertItem("Maggie Randolph", 8796);
    h1.insertItem("Zoe Cochran", 884);
    h1.insertItem("Amanda Dunlap", 9119);
    h1.insertItem("Chaz Zavala", 1871);
    h1.insertItem("Kaia Hurley", 3822);
    h1.insertItem("Rylie Gentry", 8491);
    h1.insertItem("Isaias Graham", 3965);
    h1.insertItem("Janae Rhodes", 2712);
    h1.insertItem("Jamarion Barrera", 8159);
    h1.insertItem("Briana Phelps", 9425);
    h1.insertItem("Damion Friedman", 4333);
    h1.insertItem("Carlee Horton", 5251);
    h1.insertItem("Derek Schmidt", 693);
    h1.insertItem("Imani Griffith", 3519);
    h1.insertItem("Mariyah Orr", 8430);
    h1.insertItem("Kate Suarez", 6432);
    h1.insertItem("Stella Hanson", 2840);
    h1.insertItem("Britney Sharp", 8694);
    h1.insertItem("Clarence Cabrera", 549);
    h1.insertItem("Michaela Gaines", 8902);
    h1.insertItem("Hailee Cunningham", 4778);
    h1.insertItem("Skyler Strickland", 8926);
    h1.insertItem("Stella Dennis", 4248);
    h1.insertItem("Kolby Kemp", 7107);
    h1.insertItem("Joslyn Harrington", 4266);
    h1.insertItem("Danna Poole", 8202);
    h1.insertItem("Macie Peters", 2725);
    h1.insertItem("Azaria Shields", 5425);
    h1.insertItem("Leilani Krueger", 7611);
    h1.insertItem("Kamren Walton", 5699);
    h1.insertItem("Lucia Kaiser", 2716);
    h1.insertItem("Micaela Raymond", 8183);
    h1.insertItem("Walker Horton", 9956);
    h1.insertItem("Alfred Boone", 7080);
    h1.insertItem("Amya Sellers", 7984);
    h1.insertItem("Makhi Garrett", 1742);
    h1.insertItem("Jaydon Christian", 6814);
    h1.insertItem("Raegan Mccoy", 390);
    h1.insertItem("Roy Ramos", 3908);
    h1.insertItem("Darion Mathews", 1743);
    h1.insertItem("Morgan Chen", 68);
    h1.insertItem("Kianna Stevenson", 6485);
    h1.insertItem("Devyn Doyle", 5217);
    h1.insertItem("Raphael Marquez", 5890);
    h1.insertItem("Jordon Barry", 3956);
    h1.insertItem("Shaun Cooke", 990);
    h1.insertItem("Felicity Best", 8604);
    h1.insertItem("Raquel Henderson", 7987);
    h1.insertItem("Veronica Mason", 4426);
    h1.insertItem("Eric Lester", 7312);
    h1.insertItem("Eliza Holland", 5865);
    h1.insertItem("Emely Wilkerson", 7435);
    h1.insertItem("Morgan Wiley", 6089);
    h1.insertItem("Madalyn Grimes", 7324);
    h1.insertItem("Skye Olsen", 5705);
    h1.insertItem("Beatrice Romero", 7144);
    h1.insertItem("Glenn Clayton", 6450);
    h1.insertItem("Amira Vang", 6782);
    h1.insertItem("Edith Knight", 1592);
    h1.insertItem("Brayden Briggs", 2982);
    h1.insertItem("Jamari Gates", 1808);
    h1.insertItem("Kailyn Potts", 7460);
    h1.insertItem("Alfred Wong", 9822);
    h1.insertItem("Quentin Greene", 5040);
    h1.insertItem("Maliyah Knight", 3988);
    h1.insertItem("Yareli Bowen", 8067);
    h1.insertItem("Amaya Sweeney", 7194);
    h1.insertItem("Yahir Sampson", 9281);
    h1.insertItem("Maya Turner", 6760);
    h1.insertItem("William Martin", 6119);
    h1.insertItem("Mareli Brock", 8579);
    h1.insertItem("Jacquelyn Webster", 4438);
    h1.insertItem("Simeon Fowler", 1465);
    h1.insertItem("Azaria Johns", 7563);
    h1.insertItem("Erick Ortiz", 4642);
    h1.insertItem("Dominic Ellis", 2163);
    h1.insertItem("Jan Sampson", 5298);
    h1.insertItem("Isabel Salazar", 2424);
    h1.insertItem("Camren Dennis", 6852);
    h1.insertItem("Anne Huffman", 5456);
    h1.insertItem("Izabella Leach", 590);
    h1.insertItem("Caylee Bolton", 7716);
    h1.insertItem("Fiona Dodson", 2758);
    h1.insertItem("Samara Barrett", 8935);
    h1.insertItem("Jan Molina", 3604);
    h1.insertItem("Brett Chang", 9744);
    h1.insertItem("Makenzie Woodward", 4223);
    h1.insertItem("Carlie Pham", 6214);
    h1.insertItem("Trevon Odom", 9494);
    h1.insertItem("Cailyn Bryan", 8841);
    h1.insertItem("Brittany Mata", 2814);
    h1.insertItem("Darien Acevedo", 9201);
    h1.insertItem("Alia Gates", 6279);
    h1.insertItem("Lydia Gallagher", 453);
    h1.insertItem("Elian Gardner", 8435);
    h1.insertItem("Sylvia Ramirez", 1423);
    h1.insertItem("Santiago Stewart", 3684);
    h1.insertItem("Jase Townsend", 9699);
    h1.insertItem("Jasmin Thornton", 767);
    h1.insertItem("Arianna Rivas", 5671);
    h1.insertItem("Lina Holt", 9159);
    h1.insertItem("Greyson Maldonado", 2451);
    h1.insertItem("Melody Jones", 9378);
    h1.insertItem("Alexander Page", 6090);
    h1.insertItem("Giovanni Golden", 1263);
    h1.insertItem("Leandro Werner", 9298);
    h1.insertItem("Urijah Cooper", 6584);
    h1.insertItem("Jaquan Dunlap", 2026);
    h1.insertItem("Jonas Richmond", 462);
    h1.insertItem("Karina Cobb", 9183);
    h1.insertItem("Malia Stanton", 3955);
    h1.insertItem("Amiah Ponce", 4477);
    h1.insertItem("Brycen Casey", 2109);
    h1.insertItem("Desirae Orozco", 8687);
    h1.insertItem("Kamila Rush", 6498);
    h1.insertItem("Madilynn Hill", 868);
    h1.insertItem("Meadow Dunlap", 7109);
    h1.insertItem("Shamar Singh", 3149);
    h1.insertItem("Van Henry", 7325);
    h1.insertItem("Van Rios", 9610);
    h1.insertItem("Matthias Herring", 1229);
    h1.insertItem("Ramiro Burch", 9955);
    h1.insertItem("Graham Strong", 1159);
    h1.insertItem("Lainey Khan", 4109);
    h1.insertItem("Jair Hull", 3304);
    h1.insertItem("Brynlee Miranda", 7962);
    h1.insertItem("Camille Esparza", 4780);
    h1.insertItem("Lea Mullins", 6563);
    h1.insertItem("Phoenix Weiss", 9750);
    h1.insertItem("Londyn Floyd", 5072);
    h1.insertItem("Alyson Scott", 7601);
    h1.insertItem("Vicente Bonilla", 8929);
    h1.insertItem("Zain Vaughn", 7503);
    h1.insertItem("Julius Flores", 456);
    h1.insertItem("Josephine Perkins", 7023);
    h1.insertItem("Conrad Pearson", 6799);
    h1.insertItem("Parker Mercado", 439);
    h1.insertItem("Lucy Meyer", 7037);
    h1.insertItem("Viviana Bartlett", 3492);
    h1.insertItem("Hezekiah Herrera", 2496);
    h1.insertItem("Brodie Hicks", 8567);
    h1.insertItem("Jadyn Walker", 739);
    h1.insertItem("Andy Huynh", 7938);
    h1.insertItem("Andres Clarke", 8696);
    h1.insertItem("Kathy Mejia", 2737);
    h1.insertItem("Aria Cline", 810);
    h1.insertItem("Raegan Castro", 4856);
    h1.insertItem("Logan Mcbride", 295);
    h1.insertItem("Thaddeus Bradshaw", 9084);
    h1.insertItem("Jamir Carpenter", 4650);
    h1.insertItem("Dante Burgess", 3883);
    h1.insertItem("Nickolas Lin", 5721);
    h1.insertItem("Brody Morris", 5432);
    h1.insertItem("Marlon Kelly", 2149);
    h1.insertItem("Darien Byrd", 6763);
    h1.insertItem("Jaelyn Huber", 3695);
    h1.insertItem("Keenan Keller", 227);
    h1.insertItem("Willow Merritt", 622);
    h1.insertItem("Malcolm Gay", 5786);
    h1.insertItem("Greyson Kennedy", 3085);
    h1.insertItem("Sienna Sutton", 6157);
    h1.insertItem("Alejandra Zavala", 5017);
    h1.insertItem("Kristina Lin", 132);
    h1.insertItem("Hannah Joseph", 5197);
    h1.insertItem("Carter Valencia", 2636);
    h1.insertItem("Evie Stewart", 8970);
    h1.insertItem("Lara Jordan", 3913);
    h1.insertItem("Nehemiah Fowler", 9713);
    h1.insertItem("Josephine Wilcox", 8722);
    h1.insertItem("Karla Phelps", 1868);
    h1.insertItem("Dallas Riggs", 2571);
    h1.insertItem("Kaiden Mueller", 547);
    h1.insertItem("Gaven Norris", 1915);
    h1.insertItem("Aditya Ballard", 1534);
    h1.insertItem("Jasiah Atkins", 6873);
    h1.insertItem("Aniyah Hull", 6893);
    h1.insertItem("Mohamed Serrano", 2429);
    h1.insertItem("Anastasia Spears", 5361);
    h1.insertItem("Vanessa Rosales", 343);
    h1.insertItem("Van Brandt", 5929);
    h1.insertItem("James Larson", 239);
    h1.insertItem("Malachi Spence", 2947);
    h1.insertItem("Brenda Booker", 1687);
    h1.insertItem("Graham Todd", 832);
    h1.insertItem("Griffin House", 8838);
    h1.insertItem("Mikaela Meadows", 3072);
    h1.insertItem("Wesley Weber", 267);
    h1.insertItem("Evan Mcdowell", 7925);
    h1.insertItem("Denise Barrera", 787);
    h1.insertItem("Ashly Rollins", 170);
    h1.insertItem("Seth Horn", 8292);
    h1.insertItem("Camron Mckay", 1720);
    h1.insertItem("Julia Schmitt", 7620);
    h1.insertItem("Adelyn Mcfarland", 7453);
    h1.insertItem("Nataly Cabrera", 5301);
    h1.insertItem("Giovanni Perez", 6243);
    h1.insertItem("Cade Buck", 276);
    h1.insertItem("Mariana Cooke", 9368);
    h1.insertItem("Adyson Hamilton", 2530);
    h1.insertItem("Robert Acevedo", 6846);
    h1.insertItem("Davon Hurley", 3748);
    h1.insertItem("Ryder Watson", 3935);
    h1.insertItem("Josephine Landry", 8671);
    h1.insertItem("Cadence Fowler", 4993);
    h1.insertItem("Aydin Tran", 8972);
    h1.insertItem("Paul Parrish", 7343);
    h1.insertItem("Tomas Hopkins", 9720);
    h1.insertItem("Mariyah Campbell", 8017);
    h1.insertItem("Jordan Crane", 5324);
    h1.insertItem("Malakai Montes", 226);
    h1.insertItem("Hope Webb", 1562);
    h1.insertItem("Kailee Hayden", 4966);
    h1.insertItem("Taliyah Elliott", 3584);
    h1.insertItem("Noe Cross", 964);
    h1.insertItem("Danica Preston", 2553);
    h1.insertItem("Maci Brewer", 829);
    h1.insertItem("Maxwell Newman", 7741);
    h1.insertItem("Davon Malone", 2099);
    h1.insertItem("Jaliyah Hoffman", 2700);
    h1.insertItem("Kieran Hull", 7514);
    h1.insertItem("Lilian Welch", 5545);
    h1.insertItem("Ada Merritt", 5559);
    h1.insertItem("Adrienne Scott", 5337);
    h1.insertItem("Kate Mclean", 5326);
    h1.insertItem("Lewis Molina", 553);
    h1.insertItem("Jazmin Hopkins", 4576);
    h1.insertItem("Kinley Bennett", 7010);
    h1.insertItem("Juliana Cooper", 4216);
    h1.insertItem("Giovanna Curtis", 5985);
    h1.insertItem("Kaitlin Macdonald", 8446);
    h1.insertItem("Nickolas Morse", 2690);
    h1.insertItem("Deborah Thomas", 1555);
    h1.insertItem("Roderick Chung", 9941);
    h1.insertItem("Iris Freeman", 3662);
    h1.insertItem("Deborah Sullivan", 4582);
    h1.insertItem("Jasper Kelley", 8327);
    h1.insertItem("Kaya Mata", 7086);
    h1.insertItem("Quinton Gutierrez", 7410);
    h1.insertItem("Danica Richard", 6147);
    h1.insertItem("Zion Todd", 1898);
    h1.insertItem("Duncan Shah", 3312);
    h1.insertItem("Alana Daniel", 4362);
    h1.insertItem("Leanna Hurley", 8256);
    h1.insertItem("Hayden Pennington", 4122);
    h1.insertItem("Clare Butler", 9338);
    h1.insertItem("Quinton Hall", 6817);
    h1.insertItem("Ally White", 4835);
    h1.insertItem("Keshawn Harris", 683);
    h1.insertItem("Brooke Velasquez", 3887);
    h1.insertItem("Ricky Mckee", 2827);
    h1.insertItem("Taylor Stevens", 4141);
    h1.insertItem("Cullen Liu", 9289);
    h1.insertItem("Mollie Campbell", 5685);
    h1.insertItem("Judith Mccullough", 2956);
    h1.insertItem("Arielle Johnston", 6105);
    h1.insertItem("Jimmy Montoya", 7844);
    h1.insertItem("Jovany Mayo", 3794);
    h1.insertItem("Kamari Rios", 3014);
    h1.insertItem("Estrella Castillo", 6759);
    h1.insertItem("Christopher Hawkins", 995);
    h1.insertItem("Baylee Gillespie", 6448);
    h1.insertItem("Jaelyn Ewing", 7271);
    h1.insertItem("Enrique Norman", 1669);
    h1.insertItem("Desiree Mcbride", 9465);
    h1.insertItem("Enzo Huffman", 7538);
    h1.insertItem("Finley Mendoza", 2242);
    h1.insertItem("Cordell Adams", 1740);
    h1.insertItem("Eugene Castaneda", 558);
    h1.insertItem("Douglas Wilkins", 8435);
    h1.insertItem("Shyanne Fry", 2028);
    h1.insertItem("Jax Lozano", 210);
    h1.insertItem("Bridger Kerr", 6691);
    h1.insertItem("Garrett Baker", 7873);
    h1.insertItem("Isabel Caldwell", 2072);
    h1.insertItem("Marco Chase", 8480);
    h1.insertItem("Meghan Russo", 654);
    h1.insertItem("Claire Hurst", 7788);
    h1.insertItem("Iyana Graham", 6835);
    h1.insertItem("Miguel Haley", 3166);
    h1.insertItem("Guillermo Merritt", 8184);
    h1.insertItem("Jaylan Schroeder", 4742);
    h1.insertItem("Landen Walsh", 2152);
    h1.insertItem("Rhett Snyder", 7201);
    h1.insertItem("Warren Bryan", 4051);
    h1.insertItem("Ean Petersen", 6453);
    h1.insertItem("Fernando Lam", 1765);
    h1.insertItem("Johan Davenport", 8152);
    h1.insertItem("Trent Conley", 456);
    h1.insertItem("Brian Sawyer", 7701);
    h1.insertItem("Lorelei Cohen", 288);
    h1.insertItem("Conner Stafford", 5787);
    h1.insertItem("Emmy Wall", 7333);
    h1.insertItem("Alena West", 3503);
    h1.insertItem("Jack Huber", 3202);
    h1.insertItem("Paola Steele", 7752);
    h1.insertItem("Jamarcus Savage", 6617);
    h1.insertItem("Skylar Friedman", 6011);
    h1.insertItem("Kelvin Walls", 398);
    h1.insertItem("Cristopher Castaneda", 473);
    h1.insertItem("Caleb Powers", 2019);
    h1.insertItem("Ciara Ferrell", 6308);
    h1.insertItem("Lizeth Holland", 155);
    h1.insertItem("Issac Leon", 9683);
    h1.insertItem("Markus Tanner", 9513);
    h1.insertItem("Jaime Crosby", 1278);
    h1.insertItem("Davian Roman", 4258);
    h1.insertItem("Jaelyn Peck", 9349);
    h1.insertItem("Colten Carrillo", 1809);
    h1.insertItem("Bella Mays", 1557);
    h1.insertItem("Nola Daniels", 2709);
    h1.insertItem("Juliana Sharp", 3411);
    h1.insertItem("London Thomas", 4938);
    h1.insertItem("Jaidyn Werner", 5913);
    h1.insertItem("Kelton Morrow", 7945);
    h1.insertItem("Cynthia Ellison", 2989);
    h1.insertItem("Tori Burke", 748);
    h1.insertItem("Jaidyn Mendez", 8249);
    h1.insertItem("Hayley Mclean", 5060);
    h1.insertItem("Hugh Rogers", 8478);
    h1.insertItem("Jaeden Cain", 4237);
    h1.insertItem("Kellen Stone", 769);
    h1.insertItem("Marely Clements", 5269);
    h1.insertItem("Gracelyn Giles", 7351);
    h1.insertItem("Simon Hanson", 6485);
    h1.insertItem("Wade Cortez", 5473);
    h1.insertItem("Haven Pennington", 9758);
    h1.insertItem("Haylee Gaines", 2537);
    h1.insertItem("Cloe Jefferson", 5722);
    h1.insertItem("Katherine Pollard", 9842);
    h1.insertItem("Cecelia Holder", 493);
    h1.insertItem("Serena Parsons", 1381);
    h1.insertItem("Jamal Lowery", 3878);
    h1.insertItem("Gerardo Cline", 8743);
    h1.insertItem("Kaley Mendez", 7715);
    h1.insertItem("Blake Knapp", 3044);
    h1.insertItem("Marques Hardin", 3800);
    h1.insertItem("Layla Contreras", 7669);
    h1.insertItem("Carmen Woods", 7850);
    h1.insertItem("Rowan Pennington", 3744);
    h1.insertItem("Jesus Holmes", 1713);
    h1.insertItem("Helena Griffin", 476);
    h1.insertItem("Autumn Pope", 9423);
    h1.insertItem("Skylar Grimes", 6810);
    h1.insertItem("Cody Berg", 3806);
    h1.insertItem("Jaylan Santana", 4812);
    h1.insertItem("Lucy Carney", 7829);
    h1.insertItem("Brent Montoya", 8738);
    h1.insertItem("Sienna Estrada", 1707);
    h1.insertItem("Anabel Scott", 1529);
    h1.insertItem("Eleanor Stephens", 7329);
    h1.insertItem("Marcus Bates", 3106);
    h1.insertItem("Aydin Sanchez", 8043);
    h1.insertItem("Isaac Montes", 2134);
    h1.insertItem("Jada Carpenter", 39);
    h1.insertItem("Mason Garcia", 2427);
    h1.insertItem("Bruno Jarvis", 4022);
    h1.insertItem("Aisha Preston", 4993);
    h1.insertItem("Regan Benton", 5143);
    h1.insertItem("Cooper Zhang", 814);
    h1.insertItem("Ray Pratt", 9840);
    h1.insertItem("Jessica Fischer", 334);
    h1.insertItem("Emiliano Velez", 3264);
    h1.insertItem("Carmelo Jimenez", 8955);
    h1.insertItem("Athena Holland", 8295);
    h1.insertItem("Pamela Santiago", 4510);
    h1.insertItem("Carlie Wang", 4996);
    h1.insertItem("Gage Graves", 8799);
    h1.insertItem("Leah Mejia", 7602);

    h1.removeItem(39);
    h1.removeItem(1529);

    h1.printHashTable();

    cout << "Enter a key you want to find: ";
    cin >> key_answer;
    cout << h1.findItem(key_answer) << endl;

    cout << endl;
    cout << "RESULTS HAVE BEEN SENT TO 'result_hash.txt'" << endl;

    return 0;
}
