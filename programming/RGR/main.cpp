#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>
#include <cmath>

#pragma pack(push, 1)
struct BmpFileHeader {
    uint16_t signature = 0x4D42; // "BM" в little-endian
    uint32_t fileSize = 0;
    uint16_t reserved1 = 0;
    uint16_t reserved2 = 0;
    uint32_t dataOffset = 54; // 14 + 40
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BmpInfoHeader {
    uint32_t headerSize = 40;
    int32_t width = 0;
    int32_t height = 0;
    uint16_t colorPlanes = 1;
    uint16_t bitsPerPixel = 24;
    uint32_t compression = 0;
    uint32_t imageSize = 0;
    int32_t xPixelsPerMeter = 3780; // 96 dpi
    int32_t yPixelsPerMeter = 3780;
    uint32_t colorsUsed = 0;
    uint32_t importantColors = 0;
};
#pragma pack(pop)

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

bool createBmp(const std::string& filename, int width, int height, const std::vector<Pixel>& pixels) {
    if (pixels.size() != static_cast<size_t>(width * height)) {
        return false;
    }

    int padding = (4 - (width * 3) % 4) % 4;
    int rowSize = width * 3 + padding;
    uint32_t imageSize = rowSize * height;
    uint32_t fileSize = 54 + imageSize;

    BmpFileHeader fileHeader;
    fileHeader.fileSize = fileSize;
    BmpInfoHeader infoHeader;
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.imageSize = imageSize;

    std::ofstream fout(filename, std::ios::binary);
    if (!fout) return false;

    fout.write(reinterpret_cast<const char*>(&fileHeader), 14);
    fout.write(reinterpret_cast<const char*>(&infoHeader), 40);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            size_t index = y * width + x;
            fout.write(reinterpret_cast<const char*>(&pixels[index]), 3);
        }
        if (padding > 0) {
            char pad[3] = {0, 0, 0};
            fout.write(pad, padding);
        }
    }
    fout.close();
    return true;
}

bool readBmp(const std::string& filename, int& width, int& height, std::vector<Pixel>& pixels) {
    std::ifstream fin(filename, std::ios::binary);
    if (!fin) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return false;
    }

    BmpFileHeader fileHeader;
    fin.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    if (fileHeader.signature != 0x4D42) {
        std::cerr << "Файл не является BMP" << std::endl;
        return false;
    }

    BmpInfoHeader infoHeader;
    fin.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
    if (infoHeader.bitsPerPixel != 24) {
        std::cerr << "Поддерживаются только 24-битные BMP" << std::endl;
        return false;
    }
    if (infoHeader.compression != 0) {
        std::cerr << "Поддерживается только несжатый BMP" << std::endl;
        return false;
    }

    width = infoHeader.width;
    height = infoHeader.height;
    int padding = (4 - (width * 3) % 4) % 4;

    pixels.resize(width * height);
    fin.seekg(fileHeader.dataOffset, std::ios::beg);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            size_t index = y * width + x;
            fin.read(reinterpret_cast<char*>(&pixels[index]), 3);
        }
        fin.seekg(padding, std::ios::cur);
    }
    fin.close();
    return true;
}

std::vector<int> readTextFile(const std::string& filename) {
    std::vector<int> arr;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл!\n";
        return arr;
    }
    unsigned char ch;
    while (file.get(reinterpret_cast<char&>(ch))) {
        arr.push_back(static_cast<int>(ch));
    }
    file.close();
    return arr;
}

bool writeTextFile(const std::string& filename, const std::vector<int>& arr) {
    std::ofstream fout(filename);
    if (!fout) return false;
    for (int val : arr) {
        fout << static_cast<char>(val);
    }
    fout.close();
    return true;
}

std::vector<int> pixelsToInt(const std::vector<Pixel>& pixels) {
    std::vector<int> arr;
    for (const auto& p : pixels) {
        int sum = p.blue + p.green + p.red;
        arr.push_back(sum);
    }
    return arr;
}

std::vector<Pixel> intToPixels(const std::vector<int>& ints) {
    std::vector<Pixel> pixels;
    for (int val : ints) {
        Pixel p;
        p.blue  = static_cast<uint8_t>((val / 100) * 100);
        p.green = static_cast<uint8_t>(((val / 10) % 10) * 10);
        p.red   = static_cast<uint8_t>(val % 10);
        pixels.push_back(p);
    }
    return pixels;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Чтение исходного текста
    std::vector<int> inputInt = readTextFile("input.txt");
    std::cout << "Введенный вами файл:\n";
    for (int code : inputInt) {
        std::cout << static_cast<char>(code);
    }
    std::cout << std::endl;

    // Подбор размеров изображения (квадрат, вмещающий все символы)
    int n = static_cast<int>(inputInt.size());
    if (n == 0) {
        std::cerr << "Файл пуст!" << std::endl;
        return 1;
    }
    int width = static_cast<int>(std::ceil(std::sqrt(n)));
    int height = static_cast<int>(std::ceil(static_cast<double>(n) / width));
    int totalPixels = width * height;

    // Преобразование чисел в пиксели и дополнение до totalPixels нулями
    std::vector<Pixel> outputPixel = intToPixels(inputInt);
    outputPixel.resize(totalPixels, {0, 0, 0});

    // Создание BMP
    if (!createBmp("output.bmp", width, height, outputPixel)) {
        std::cerr << "Ошибка создания BMP!" << std::endl;
        return 1;
    }

    // Чтение BMP обратно
    std::vector<Pixel> inputPixel;
    int readWidth = 0, readHeight = 0;
    if (!readBmp("output.bmp", readWidth, readHeight, inputPixel)) {
        std::cerr << "Ошибка чтения BMP!" << std::endl;
        return 1;
    }

    // Преобразование пикселей в числа
    std::vector<int> outputInt = pixelsToInt(inputPixel);
    // Обрезаем до исходной длины (убираем добавленные нули)
    outputInt.resize(n);

    std::cout << "Считанный из рисунка текст:\n";
    for (int code : outputInt) {
        std::cout << static_cast<char>(code);
    }
    std::cout << std::endl;

    return 0;
}