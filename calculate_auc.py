import numpy as np
import pandas as pd
from sklearn import metrics

def calculate_auc(labels, probs):
    assert len(labels) == len(probs)
    pos_num = sum(labels)
    neg_num = len(labels) - pos_num
    indexes = np.argsort(probs)[::-1]
    pos_acc = 0
    neg_acc = 0
    auc = 0
    for i in indexes:
        if labels[i] == 1:
            pos_acc += 1
        else:
            neg_acc += 1
            auc += pos_acc
    return auc / (pos_num * neg_num)