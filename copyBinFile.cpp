    std::fstream fileName;
    fileName.open("testBin.bin", std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
    std::fstream fileName2;
    fileName2.open("testBin2.bin", std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);

    if (!fileName.is_open()) {
        std::cerr << "fileName not found" << std::endl;
        return 1;
    }

    if (!fileName2.is_open()) {
        std::cerr << "fileName2 not found" << std::endl;
        return 1;
    }

    struct Test {
        char ch;
        int numb;
        void print() const {
            std::cout << ch << " " << numb << std::endl;
        }
    };

    Test obj = { 'a', 33 };
    Test obj2 = { 'b', 66 };
    fileName.write((char*)&obj, sizeof(obj));
    fileName.write((char*)&obj2, sizeof(obj2));

    fileName.seekg(0, std::ios::beg);
    Test temp;

    while (fileName.read((char*)&temp, sizeof(temp))) {
        fileName2.write((char*)&temp, sizeof(temp));
    }


    fileName2.seekg(0, std::ios::beg);
    Test temp2;
    while (fileName2.read((char*)&temp2, sizeof(temp2))) {
        temp2.print();
    }

    fileName.close();
    fileName2.close();
