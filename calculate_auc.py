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


def main():
    data = pd.read_csv("", usecols=['label', 'prob'])
    labels = data['label'].values
    probs = data['prob'].values
    auc = calculate_auc(labels, probs)
    print("calculate_auc: %s" % auc)

    fpr, tpr, _ = metrics.roc_curve(labels, probs, pos_label=1)
    sklearn_auc = metrics.auc(fpr, tpr)
    print("sklearn_auc: %s" % sklearn_auc)


if __name__ == '__main__':
    main()
