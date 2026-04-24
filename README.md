# 🧠 ỨNG DỤNG THI TRẮC NGHIỆM C++
## 📌 Giới thiệu dự án
Đây là dự án ứng dụng thi trắc nghiệm trên môi trường **Console (Terminal)**, được viết hoàn toàn bằng ngôn ngữ C++.

## 🚀 Các chức năng chính
### 1. Chức năng cơ bản
- Load dữ liệu là bộ câu hỏi và đáp án từ file.

- Hiển thị: số lượng câu hỏi, thời gian hiện hành thực hiện bài thi.

- Cho phép nhập thông tin cá nhân của thí sinh.

- Hiển thị các câu hỏi và cho phép thí sinh nhập phương án trả lời cho mỗi câu hỏi.

- Cho phép thí sinh có thể “skip”  câu hỏi và trả lời sau.

- Cho phép thí sinh có thể thay đổi câu trả lời cho từng câu hỏi.

- Hiển thị kết quả bài thi gồm thông tin thí sinh, thời gian bắt đầu bài thi, tổng thời gian làm bài của thí sinh, số câu trả lời đúng, tổng điểm.

---

### 2. Chức năng sáng tạo 
- Xáo trộn đề thi: Xáo trộn ngẫu nhiên thứ tự câu hỏi và thứ tự các phương án (A, B, C, D) cho mỗi lượt thi.

- Đồng hồ đếm ngược: Thiết lập giới hạn thời gian làm bài. Hệ thống kiểm tra liên tục, nếu hết giờ sẽ tự động khóa bài, kết thúc thi và chuyển sang màn hình tính điểm.

- Lọc câu hỏi theo độ khó/chủ đề: Người dùng có thể tùy chọn mức độ thi (Dễ, Trung bình, Khó). Hệ thống sẽ tự động lọc các câu hỏi phù hợp từ mảng gốc sang mảng thi.

- Bảng điều khiển tổng quan: Trước khi nộp bài, thí sinh có thể xem màn hình tổng kết trạng thái các câu để rà soát lại bài làm.

---

### 3. Quản lý kết quả & Phân tích 
- Lưu trữ lịch sử thi (File I/O): Tự động ghi lại kết quả (Tên, Mã, Điểm, Thời gian) vào tệp tin sau mỗi lượt thi.

- Bảng xếp hạng: Đọc dữ liệu từ file lịch sử, áp dụng thuật toán sắp xếp để xếp hạng điểm số giảm dần và vinh danh Top 5 hoặc Top 10 thí sinh xuất sắc nhất.

- Chế độ xem lại: Cho phép thí sinh đối chiếu bài làm sau khi biết điểm. Màn hình sẽ hiển thị: Nội dung câu hỏi, Đáp án đã chọn, Kết quả (Đúng/Sai) và Đáp án chính xác. Tích hợp thêm bộ lọc thông minh "Chỉ xem các câu làm sai".

- Thống kê hiệu suất: Tính toán tự động tỷ lệ % câu trả lời đúng và ước lượng thời gian trung bình tiêu tốn cho mỗi câu hỏi.

---

## 📁 Cấu trúc File
- main.cpp: Tệp chứa hàm main và luồng chạy chính của giao diện.

- functions.cpp / functions.h: Định nghĩa cấu trúc Struct và các hàm xử lý logic (trộn đề, tính điểm, đếm giờ...).

- data.txt: Tệp lưu trữ ngân hàng câu hỏi gốc

- history.txt / rank.txt: Tệp lưu trữ lịch sử thi và bảng xếp hạng
