# Student-Attendance-System-Group12

Software Engineering Project : Student-Attandance-System


**Phase 2: Implementation \& Testing\*\***



\---



\## 1. Thời hạn và Quy cách nộp bài (Submission)

\*   \*\*Hạn chót (Deadline):\*\* Chủ Nhật, ngày 13/09/2026 lúc 22:59.

\*   \*\*Định dạng nộp:\*\* Nén toàn bộ dữ liệu vào một thư mục đặt tên theo cú pháp `ProgAndTest\_Group12`.

\*   \*\*Thành phần bắt buộc trong thư mục:\*\*

&#x20;   \*   Source code (bao gồm các file `.cpp`, `.h`).

&#x20;   \*   Tài liệu kiểm thử (Testing document).

&#x20;   \*   File cấu hình Docker (Docker file).

&#x20;   \*   File minh chứng việc sử dụng các công cụ và bảng phân công công việc (Task assignment).



\## 2. Yêu cầu Khâu Lập trình (Programming)

\*   \*\*Bám sát đặc tả:\*\* Mã nguồn phải được lập trình chính xác theo bản thiết kế chuẩn (final) đã nộp vào ngày 03/09, đảm bảo hệ thống vận hành đầy đủ các chức năng.

\*   \*\*Tuân thủ OOP \& Kiến trúc:\*\* Bắt buộc lập trình hướng đối tượng (OOP) theo đúng Class Diagram đã chốt và phải ứng dụng kiến trúc \*\*MVC (Model-View-Controller)\*\* đã học ở Chương 3 để xây dựng hệ thống.

\*   \*\*Giao diện:\*\* Chương trình bắt buộc phải sử dụng giao diện đồ họa (GUI), không dùng màn hình console.



\## 3. Yêu cầu Khâu Kiểm thử \& Điểm số (Testing \& Grading)

\*   \*\*Công cụ và Docker:\*\* Nhóm cần đọc lại "Instructions for making group projects" để áp dụng chính xác các công cụ kiểm thử và Docker vào dự án.

\*   \*\*Biểu mẫu Test Case (Cực kỳ quan trọng):\*\* Bắt buộc phải sử dụng đúng biểu mẫu `Testing Document Template` để thiết kế các kịch bản kiểm thử; nếu sử dụng sai mẫu sẽ bị chấm 0 điểm cho phần này.

\*   \*\*Phân bổ điểm số:\*\* Trọng số 2 điểm của đợt này sẽ dành riêng cho phần nghiên cứu và sử dụng các công cụ bao gồm Drawio, GitHub, các tool kiểm thử và Docker.

\*   \*\*Quản lý nhóm:\*\* Leader phải có trách nhiệm phân công rõ ràng các thành viên thực hiện lập trình, kiểm thử, thiết kế test case và tìm hiểu tool.



\## 4. Quy định Báo cáo (Presentation)

\*   \*\*Thời gian bắt đầu:\*\* Các nhóm sẽ bắt đầu báo cáo vào thứ Hai tuần sau, ngày 14/09.

\*   \*\*Giờ giấc:\*\* Báo cáo có mặt sớm từ lúc 6:45 sáng.

\*   \*\*Cấu trúc thuyết trình:\*\* Bài báo cáo phải trình bày theo thứ tự: Triển khai Lập trình (Program Implementation) trước, sau đó mới đến phần Kiểm thử (Testing).

\*   \*\*Giới hạn thời gian:\*\* Tối đa 15 phút để hoàn thành toàn bộ bài thuyết trình.



\---



\## 5. Bảng Phân Công Công Việc (Task Assignment)

\*(Deadline nội bộ ghép code: 22:00, 11/09)\*



| STT | Thành viên | Vai trò | Nhiệm vụ cụ thể | Công cụ áp dụng (Minh chứng) |

| :--- | :--- | :--- | :--- | :--- |

| \*\*1\*\* | \*\*Phan Hữu Ý\*\* \*(Leader)\* | \*\*DevOps \& System Architect\*\* | - Khởi tạo repository GitHub, phân quyền branch cho nhóm.<br>- Thiết lập khung kiến trúc MVC (Model-View-Controller) cho source code C++.<br>- Viết file Dockerfile để đóng gói môi trường C++/Qt/SQLite.<br>- Tổng hợp hình ảnh minh chứng dùng tool, nén thư mục ProgAndTest\_Group12 nộp đúng hạn. | GitHub, Docker, C++ Compiler |

| \*\*2\*\* | \*\*Hồ Thiên Phú\*\* | \*\*Database \& Backend Engineer\*\* | - Khởi tạo file CSDL SQLite dựa trên bản ERD chuẩn.<br>- Viết các hàm C++ thực thi truy vấn (CRUD) kết nối với DB.<br>- Lập trình backend cho FR1 (Quản lý Account) và FR6 (Xuất dữ liệu Report). | SQLite, C++, GitHub |

| \*\*3\*\* | \*\*Nguyễn Ngọc Như Quỳnh\*\* | \*\*Core OOP Dev \& Unit Tester\*\* | - Lập trình các Class C++ đúng 100% theo Class Diagram (User, Session, Record).<br>- Viết thuật toán cho FR3 (Sinh mã QR/PIN) và FR8 (Đếm ngược TTL \& Xác thực).<br>- Sử dụng tool (QtTest/GoogleTest) để viết Unit Test tự động cho các hàm cốt lõi. | C++, Qt Framework, GoogleTest / QtTest |

| \*\*4\*\* | \*\*Nguyễn Đặng Huyền Trâm\*\* | \*\*Frontend (GUI) Developer\*\* | - Sử dụng Qt Designer thiết kế giao diện đồ họa cho 4 màn hình (Login, Dashboard, Check-in, Report) bám sát Wireframe.<br>- Kết nối các nút bấm trên giao diện (Signals) với các hàm xử lý logic (Slots) do Phú và Quỳnh viết. | Qt Designer, C++, GitHub |

| \*\*5\*\* | \*\*Trịnh Nguyễn Kỳ Anh\*\* | \*\*QA Lead (Trưởng nhóm Kiểm thử)\*\* | - Tải và tuân thủ tuyệt đối biểu mẫu Testing Document Template của giảng viên.<br>- Viết Test Case cho 10 Use Case áp dụng kỹ thuật Phân vùng tương đương (Chapter 5).<br>- Chạy System Test trên giao diện Qt cuối cùng và điền cột Thực tế (Actual Output). | Biểu mẫu Template, Black-box testing |

