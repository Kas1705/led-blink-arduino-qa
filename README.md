<div align="center">

# 💡 LED Blink: QA-Documented Arduino Project

**A non-blocking LED blink program with QA issues tracked and resolved through GitHub Issues.**

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![GitHub Issues](https://img.shields.io/github/issues-closed/<your-username>/led-blink-qa?style=for-the-badge&logo=github)
![Version](https://img.shields.io/badge/version-1.1.0-blue?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)

</div>

---

## 📑 Table of Contents

- [📌 Overview](#-overview)
- [🔧 Hardware Required](#-hardware-required)
- [🔌 Circuit and Wiring](#-circuit-and-wiring)
- [🚀 Getting Started](#-getting-started)
- [📝 Code Description](#-code-description)
- [🐞 QA Issues Logged](#-qa-issues-logged)
- [🤝 Collaboration Summary](#-collaboration-summary)
- [🗂️ Project Planning and Tracking](#️-project-planning-and-tracking)
- [🎓 Learning Outcomes](#-learning-outcomes)
- [📂 Repository Structure](#-repository-structure)
- [👤 Author](#-author)

---

## 📌 Overview

This project blinks an LED at a fixed interval and prints each state change to the Serial Monitor. It was built for the **Project Management** course (Course Code: 2307476T, CO2) to demonstrate how **GitHub** supports transparency, traceability and teamwork in electronics projects.

The main focus is the QA workflow: issues were logged, analysed for root cause, fixed on a branch, and closed through a Pull Request.

🔗 **Repository:** `https://github.com/<your-username>/led-blink-qa`

---

## 🔧 Hardware Required

| Component | Quantity | Notes |
|-----------|----------|-------|
| 🟦 Arduino Uno (or compatible) | 1 | Any board with `LED_BUILTIN` works |
| 💡 LED (any colour) | 1 | Optional if using the on-board LED |
| ⚡ 220 Ω resistor | 1 | Current limiting |
| 🔗 Jumper wires | 2 | |
| 🍞 Breadboard | 1 | |
| 🔌 USB cable | 1 | Power and programming |

---

## 🔌 Circuit and Wiring

```
Arduino Pin 13 ──► 220 Ω resistor ──► LED anode (+, long leg)
                                      LED cathode (−, short leg) ──► GND
```

> 💡 **Tip:** Most Arduino boards already have an on-board LED on pin 13, so the sketch runs even without external wiring.

---

## 🚀 Getting Started

1. 📥 **Clone the repository**
```bash
   git clone https://github.com/<your-username>/led-blink-qa.git
```
2. 📂 Open `LED_Blink/LED_Blink.ino` in the **Arduino IDE**.
3. 🔌 Connect the board and select the correct **Board** and **Port** under *Tools*.
4. ⬆️ Click **Upload**.
5. 🖥️ Open the **Serial Monitor** at **9600 baud** to see the logs.

Expected output:

```
LED_Blink v1.1.0 started
LED: ON
LED: OFF
LED: ON
...
```

---

## 📝 Code Description

| Element | Purpose |
|---------|---------|
| `LED_PIN` | Uses `LED_BUILTIN`, falling back to pin 13 |
| `BLINK_INTERVAL_MS` | Time between LED toggles (500 ms) |
| `SERIAL_BAUD` | Serial speed (9600) |
| `millis()` timing | Toggles the LED without blocking the CPU |
| `Serial.println()` | Logs each state change for debugging |

The `loop()` function never blocks, so sensor reads or button checks can be added later without disturbing the blink timing.

---

## 🐞 QA Issues Logged

| # | 🏷️ Issue | 🔍 Root Cause | ✅ Fix | ⚠️ Severity | Status |
|---|----------|--------------|--------|-------------|--------|
| [#1](../../issues/1) | Hard-coded pin and delay values | Magic numbers in code | Named constants | 🟢 Low | ✔️ Closed |
| [#2](../../issues/2) | No runtime debug visibility | No serial output | `Serial.begin()` and state logs | 🟡 Medium | ✔️ Closed |
| [#3](../../issues/3) | Board blocked during `delay()` | Blocking call halts the CPU | `millis()`-based timing | 🔴 High | ✔️ Closed |
| [#4](../../issues/4) | Fails when LED is not on pin 13 | Board-specific assumption | Use `LED_BUILTIN` | 🟡 Medium | ✔️ Closed |
| [#5](../../issues/5) | First serial messages lost on native-USB boards | Serial not ready at startup | Wait loop with 2 s timeout | 🟢 Low | ✔️ Closed |

Each issue contains a **5-Why root cause analysis** in its comments and is closed by a Pull Request.

---

## 🤝 Collaboration Summary

- 🐛 Issues were opened with labels (`bug`, `enhancement`) and a severity level.
- 💬 Discussion and root cause analysis were recorded as issue comments.
- 🌿 Fixes were developed on a separate branch: `fix/issue-3-nonblocking-delay`.
- 🔀 A Pull Request with `Closes #3, #4, #5` linked the code changes to the issues.
- 📜 Commit history gives full traceability from problem to fix.

---

## 🗂️ Project Planning and Tracking

| Phase | Task | Tool | Status |
|-------|------|------|--------|
| 1️⃣ Setup | Create repo, add base sketch | GitHub | ✅ Done |
| 2️⃣ Testing | Review code, log QA issues | GitHub Issues | ✅ Done |
| 3️⃣ Fixing | Resolve issues on a feature branch | Git branches and commits | ✅ Done |
| 4️⃣ Review | Open PR, comment, merge | Pull Requests | ✅ Done |
| 5️⃣ Reporting | Prepare report, upload to Moodle | Moodle | ✅ Done |

> 📌 Optional: add a GitHub **Project board** (To Do / In Progress / Done) and link its screenshot here.

---

## 🎓 Learning Outcomes

- 🔎 GitHub Issues make defects **visible and traceable** from report to fix.
- 🧩 Root cause analysis (5-Why) prevents repeating the same class of bugs.
- ⏱️ Non-blocking `millis()` timing is more scalable than `delay()` in embedded systems.
- 🔁 Branches and Pull Requests bring code review discipline to hardware projects.
- 📚 Version-controlled documentation keeps electronics and software work in sync.

---

## 📂 Repository Structure

```
led-blink-qa/
├── 📁 LED_Blink/
│   └── 📄 LED_Blink.ino
├── 📁 docs/
│   ├── 🖼️ circuit-diagram.png
│   └── 🖼️ serial-monitor-output.png
├── 📄 README.md
└── 📄 LICENSE
```

---

## 👤 Author

**Kishan**
🎓 B.Tech E&TC, MIT Academy of Engineering, Alandi, Pune
📘 Course: Project Management (2307476T), Semester VII

---

<div align="center">

⭐ If this helped you, consider giving the repo a star!

</div>
