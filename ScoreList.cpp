#include "ScoreList.h"

Score::Score(string name, int score) {

    this->name = name;
    this->score = score;
}

void ScoreList::loadFromFile() {

    ifstream read_file("Highscore.txt");

    string read_name;
    string read_score;
    string read_string;
    bool is_read_name = true;
    bool is_load_success = false;

    // อ่านไฟล์ทีละบรรทัด
    while (getline(read_file, read_string)) {

        // ถ้าเป็นชื่อ ให้บันทึกค่าที่อ่านได้ลงในตัวแปร
        if (is_read_name) read_name = read_string;
        else { // ถ้าเป็นคะแนน ก็บันทึกคะแนนลง

            read_score = read_string;

            // แปลงคะแนนที่อ่านได้เป็น int
            int score_int;
            stringstream ss;
            ss << read_score;
            ss >> score_int;

            // สร้าง Class Score แล้วยัดลง Vector
            this->score_list.push_back(Score(read_name, score_int));
        }

        // สลับอ่านชื่อกับคะแนน
        is_read_name = !is_read_name;
        is_load_success = true;
    }

    if (is_load_success) {

        std::cout << "Load Success!" << std::endl;
        return;
    }
    std::cout << "Load Failed! : Data not found." << std::endl;
}

void ScoreList::saveToFile() {

    ofstream save_file("Highscore.txt");

    // บันทึกคะแนนชื่อลงทีละบรรทัดในไฟล์
    for (int i = 0; i < this->score_list.size(); i++) {

        save_file << this->score_list.at(i).name << endl;
        save_file << this->score_list.at(i).score << endl;
    }
    save_file.close();

    cout << "Save Success ! : " << this->score_list.size() << " entries." << endl;
}

void ScoreList::addScoreToList(Score player) {

    // ลูปหาชื่อซ้ำ
    for (int i = 0; i < score_list.size(); i++) {

        if (player.name == score_list[i].name) {

            score_list.erase(score_list.begin() + i);
        }
    }

    // ลูปบันทึกชื่อ
    for (int i = 0; i < score_list.size(); i++) {

        // ถ้าเจอชื่อซ้ำคะแนนซ้ำ ไม่ต้องบันทึก
        if (player.score == score_list[i].score && player.name == score_list[i].name) {

            cout << "Save failed ! : found duplicate name and score." << endl;
            return;
        }

        // ถ้าคะแนนเยอะกว่า คะแนนที่ตำแหน่ง i ให้ยัดชื่อลงก่อนหน้า i
        if (player.score > score_list[i].score) {
            score_list.insert(score_list.begin() + i, player);

            cout << "Save Success ! : " << player.name << " with a score of " << player.score << " points." << endl;
            return;
        }
    }

    // ไม่มีคะแนนอยู่ในรายการจะเพิ่มไปเลย
    score_list.insert(score_list.end(), player);

    cout << "Save Success ! : " << player.name << " with a score of " << player.score << " points." << endl;
}

vector<Score> ScoreList::getScoreList()
{
    return vector<Score>();
}
