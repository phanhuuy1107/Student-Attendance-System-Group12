FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    build-essential \
    qtbase5-dev \
    qt5-qmake \
    libsqlite3-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . /app
RUN qmake Group12_Attendance.pro
RUN make
CMD ["./Group12_Attendance"]