# Pre-loaded Data Reference

## Train Numbers (001 format)

| Train No | Train Name | From | To |
|----------|------------|------|-----|
| **001** | Rajdhani Express | Mumbai | Delhi |
| **002** | Karnataka Express | Bangalore | Delhi |
| **003** | Howrah Rajdhani | Kolkata | Delhi |
| **004** | Shatabdi Express | Mumbai | Ahmedabad |
| **005** | Tamil Nadu Express | Chennai | Delhi |
| **006** | Goa Express | Mumbai | Goa |
| **007** | Coromandel Express | Chennai | Kolkata |
| **008** | Duronto Express | Delhi | Kolkata |

> You can type **1** or **001** — both work.

## Passengers

| ID | Name | Phone |
|----|------|-------|
| 001 | Rahul Sharma | 9876543210 |
| 002 | Priya Patel | 9123456780 |
| 003 | Amit Kumar | 9988776655 |
| 004 | Sneha Reddy | 9012345678 |
| 005 | Vikram Singh | 8899001122 |

## Bookings (PNR)

| PNR | Train | Status |
|-----|-------|--------|
| PNR001 | 001 | Confirmed |
| PNR002 | 001 | Confirmed |
| PNR003 | 004 | Confirmed |
| PNR004 | 002 | Confirmed |
| PNR005 | 003 | Waiting |

## Quick Test

1. Menu **6** → Train **001**
2. Menu **5** → Name **Rahul**
3. Menu **2** → Cancel **PNR001**
4. Menu **4** → Train **001** (498 seats)

## Reset

```bash
make reset
make run
```
