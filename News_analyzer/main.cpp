#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

// ===== Очистка HTML от тегов =====
std::string extractTextFromHTML(const std::string& html) {
    std::string text = html;

    // Удаляем HTML-теги
    text = std::regex_replace(text, std::regex("<[^>]*>"), " ");
    // Удаляем HTML-сущности
    text = std::regex_replace(text, std::regex("&[^;]+;"), " ");
    // Убираем лишние пробелы
    text = std::regex_replace(text, std::regex("\\s+"), " ");

    // Приводим к нижнему регистру
    for (char& c : text)
        c = std::tolower(static_cast<unsigned char>(c));

    return text;
}

// ===== Подсчёт совпадений слов =====
int countWordMatches(const std::string& text, const std::vector<std::string>& words) {
    int count = 0;
    for (const auto& w : words) {
        try {
            std::regex r("\\b" + w + "\\b");
            count += std::distance(std::sregex_iterator(text.begin(), text.end(), r), std::sregex_iterator());
        } catch (...) {
            // пропускаем некорректные regex-шаблоны
        }
    }
    return count;
}

int main() {
    std::string filename = "page.html";
    std::remove(filename.c_str()); // очистка файла

    std::string url;
    std::cout << "Enter news URL: ";
    std::getline(std::cin, url);

#if defined(_WIN32)
    std::string command = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + filename + "'\"";
#else
    std::string command = "curl -s -L \"" + url + "\" -o " + filename;
#endif

    std::cout << "\nDownloading page...\n";
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Failed to download the page.\n";
        return 1;
    }

    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: cannot open file.\n";
        return 1;
    }

    std::string html((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();

    std::string text = extractTextFromHTML(html);

    // ===== Расширенный словарь (EN + UA + RU) =====
    std::vector<std::string> positiveWords = {
        // English
        "good","great","excellent","positive","happy","success","growth","improve","strong","win","benefit","hope","progress",
        "profit","solution","peace","love","joy","safe","stable","optimistic","bright","healthy","achievement",
        "freedom","innovation","victory","kind","support","amazing","develop","rise","advance","favorable","increase",
        "help","recovery","strength","honest","renew","opportunity","calm","collaboration","unity","trust","inspire",
        "smart","hero","secure","improvement","wonderful","smile","greatest","honor","peaceful","prosper","comfort",
        "dream","better","kindness","achievement","celebrate","hopeful","win","positive","renewal","respect",
        "friendly","bright","open","helpful","resilient","achieve","trustworthy","loyal","courage","succeed",

        // Ukrainian
        "добрий","чудовий","успіх","щастя","зростання","перемога","надія","здоровий","свобода","мир","дружба",
        "підтримка","розвиток","зміцнення","досягнення","спокій","впевненість","радість","покращення","любов",
        "вдячність","переможний","сильний","стабільність","надійний","відновлення","світлий","позитивний","щирий",
        "співпраця","успішний","співчуття","натхнення","розумний","герой","мужність","гуманність","захист","чесність",
        "єдність","мирний","оптимізм","доброта","турбота","добробут","успіхи","співдружність","розквіт","вдосконалення",

        // Russian
        "хороший","отличный","победа","радость","успех","мир","любовь","дружба","поддержка","здоровье","свобода",
        "надежда","достижение","спокойствие","уверенность","восстановление","развитие","добро","помощь","улучшение",
        "позитивный","сильный","умный","герой","честность","мирный","оптимизм","стабильность","безопасность",
        "доброта","порядок","сплоченность","чистота","добродетель","радостный","успешный","сияние","вдохновение",
        "верность","сотрудничество","понимание","благодарность","смелость","спокойный","вежливость","достижения"
    };

    std::vector<std::string> negativeWords = {
        // English
        "bad","sad","crisis","negative","fail","loss","weak","decline","conflict","war","problem","danger","threat",
        "damage","collapse","fear","pain","death","disease","hate","poor","disaster","corruption","fraud","crime",
        "angry","violence","struggle","risk","fall","attack","error","chaos","panic","bankrupt","enemy","pressure",
        "tension","scandal","hurt","greed","crash","pollution","tragedy","poverty","unstable","suffer","unrest",
        "fearful","losses","defeat","sadness","failure","terror","violence","worry","decline","corrupt","dirty",
        "broken","dangerous","lies","unfair","trouble","abuse","hate","harm","storm","confused","unhappy","collapse",

        // Ukrainian
        "поганий","сумний","криза","війна","поразка","загроза","страх","ненависть","злочин","смерть","хвороба",
        "біда","корупція","біль","трагедія","катастрофа","бідність","падіння","помилка","конфлікт","розлад",
        "небезпека","поранення","зрада","насильство","хаос","зневіра","втрата","зруйнування","нестабільність",
        "злидні","ненадійність","горе","паніка","розпад","жорстокість","тривога","ненависть","загибель","агресія",
        "ворог","обман","слабкість","несправедливість","кричущий","розчарування","панічний","сум","депресія","зниження",

        // Russian
        "плохой","грустный","кризис","война","поражение","угроза","страх","ненависть","смерть","болезнь","боль",
        "катастрофа","бедность","ошибка","конфликт","опасность","распад","разрушение","нестабильность","коррупция",
        "зло","насилие","хаос","паника","утрата","потеря","убийство","катастрофический","шок","вражда","разочарование",
        "депрессия","панический","скандал","напряжение","катастрофа","несправедливость","грех","жестокость",
        "обман","разруха","тревога","злоба","разлад","агрессия","мошенничество","предательство","плач","упадок"
    };

    // ===== Анализ =====
    int posCount = countWordMatches(text, positiveWords);
    int negCount = countWordMatches(text, negativeWords);

    std::cout << "\n=== Sentiment Analysis ===\n";
    std::cout << "Positive words: " << posCount << "\n";
    std::cout << "Negative words: " << negCount << "\n";

    std::string overall;
    if (posCount > negCount)
        overall = "POSITIVE";
    else if (negCount > posCount)
        overall = "NEGATIVE";
    else
        overall = "NEUTRAL";

    std::cout << "Overall sentiment: " << overall << "\n";

    std::ofstream out("analysis_result.txt");
    out << "URL: " << url << "\n";
    out << "Positive words: " << posCount << "\n";
    out << "Negative words: " << negCount << "\n";
    out << "Overall sentiment: " << overall << "\n";
    out.close();

    std::cout << "\nResults saved to 'analysis_result.txt'\n";
    return 0;
}
