#!/bin/bash

# Проверка: если нет аргументов — справка
if [ $# -eq 0 ]; then
    echo "Использование:"
    echo "  $0 -o summa ЧИСЛО1 ЧИСЛО2 [ЧИСЛО3] [ЧИСЛО4]"
    echo "  $0 --operation subtract ЧИСЛО1 ЧИСЛО2 [ЧИСЛО3] [ЧИСЛО4]"
    echo ""
    echo "Операции:"
    echo "  summa    — суммирование всех операндов"
    echo "  subtract — вычитание из первого операнда всех остальных"
    echo ""
    echo "Операндов: от 2 до 4"
    exit 0
fi

# Разбор аргументов
OPERATION=""
NUMBERS=()

while [ $# -gt 0 ]; do
    case "$1" in
        -o|--operation)
            shift
            OPERATION="$1"
            ;;
        *)
            NUMBERS+=("$1")
            ;;
    esac
    shift
done

# Проверка операции
if [ -z "$OPERATION" ]; then
    echo "Ошибка: не указана операция. Используйте -o summa или --operation subtract"
    exit 1
fi

# Проверка количества операндов
COUNT=${#NUMBERS[@]}
if [ "$COUNT" -lt 2 ] || [ "$COUNT" -gt 4 ]; then
    echo "Ошибка: нужно от 2 до 4 операндов. Введено: $COUNT"
    exit 1
fi

# Выполнение операции
case "$OPERATION" in
    summa)
        RESULT=0
        for N in "${NUMBERS[@]}"; do
            RESULT=$((RESULT + N))
        done
        echo "Сумма: $RESULT"
        ;;
    subtract)
        RESULT=${NUMBERS[0]}
        for ((i=1; i<COUNT; i++)); do
            RESULT=$((RESULT - NUMBERS[i]))
        done
        echo "Разность: $RESULT"
        ;;
    *)
        echo "Ошибка: неизвестная операция '$OPERATION'"
        echo "Доступно: summa, subtract"
        exit 1
        ;;
esac
