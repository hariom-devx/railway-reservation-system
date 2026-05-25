# GitHub Upload Commands

## Step 1: Initialize Git Repository

```bash
cd "/Users/hariom/cursor/Railway Reservation System"

git init
git branch -M main
```

## Step 2: Stage and Commit

```bash
git add .
git status
git commit -m "$(cat <<'EOF'
Add Railway Reservation System in C with core data structures

Console-based ticket management using Queue, Linked List, Stack,
and BST with file persistence, admin panel, and modular headers.
EOF
)"
```

## Step 3: Create GitHub Repository

1. Go to [https://github.com/new](https://github.com/new)
2. Repository name: `railway-reservation-system`
3. Description: `Console-based Railway Reservation System in C using Queue, Linked List, Stack, and BST`
4. Choose **Public**
5. Do **not** initialize with README (we already have one)
6. Click **Create repository**

## Step 4: Push to GitHub

```bash
git remote add origin https://github.com/YOUR_USERNAME/railway-reservation-system.git
git push -u origin main
```

Replace `YOUR_USERNAME` with your GitHub username.

## Step 5: SSH Alternative

```bash
git remote add origin git@github.com:YOUR_USERNAME/railway-reservation-system.git
git push -u origin main
```

---

## Recommended Repository Topics

Add these topics on GitHub for discoverability:

```
c programming data-structures algorithms console-application
railway-reservation linked-list stack queue binary-search-tree
file-handling college-project internship-project
```

---

## Professional README Badges (Optional)

Add to top of README after publishing:

```markdown
![Build](https://img.shields.io/badge/Build-Passing-brightgreen)
![C](https://img.shields.io/badge/C-C11-blue)
```

---

## Clone Command (for recruiters)

```bash
git clone https://github.com/YOUR_USERNAME/railway-reservation-system.git
cd railway-reservation-system
make && ./railway_system
```
